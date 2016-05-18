/** additional window effect
 * deskcloud effect **/
deskcloudPopupEffect = Class.create();
deskcloudPopupEffect.prototype = {
	initialize: function(htmlElement) {
		this.html = $(htmlElement);
		this.options = Object.extend({className: "popup_effect", duration: 0.4}, arguments[1] || {});
	},
	show: function(element, options) {
		var position = Position.cumulativeOffset(this.html);
		var size = this.html.getDimensions();
		var bounds = element.win.getBounds();
		this.window =  element.win;
		// Create a div
		if (!this.div) {
			this.div = document.createElement("div");
			this.div.className = this.options.className;
			this.div.style.height = size.height + "px";
			this.div.style.width  = size.width  + "px";
			this.div.style.top    = position[1] + "px";
			this.div.style.left   = position[0] + "px";
			this.div.style.position = "absolute"
			document.body.appendChild(this.div);
		}
		if (this.options.fromOpacity)
			this.div.setStyle({opacity: this.options.fromOpacity})
		this.div.show();
		var style = "top:" + bounds.top + ";left:" +bounds.left + ";width:" + bounds.width +";height:" + bounds.height;
		if (this.options.toOpacity)
			style += ";opacity:" + this.options.toOpacity;
		new Effect.Morph(this.div ,{style: style, duration: this.options.duration, afterFinish: this._showWindow.bind(this)});
	},
	hide: function(element, options) {
		var position = Position.cumulativeOffset(this.html);
		var size = this.html.getDimensions();
		this.window.visible = true;
		var bounds = this.window.getBounds();
		this.window.visible = false;

		this.window.element.hide();
		this.div.style.height = bounds.height;
		this.div.style.width  = bounds.width;
		this.div.style.top    = bounds.top;
		this.div.style.left   = bounds.left;

		if (this.options.toOpacity)
			this.div.setStyle({opacity: this.options.toOpacity})
		this.div.show();
		var style = "top:" + position[1] + "px;left:" + position[0] + "px;width:" + size.width +"px;height:" + size.height + "px";
		if (this.options.fromOpacity)
			style += ";opacity:" + this.options.fromOpacity;
		new Effect.Morph(this.div ,{style: style, duration: this.options.duration, afterFinish: this._hideDiv.bind(this)});
	},
	_showWindow: function() {
		this.div.hide();
		this.window.element.show();
	},
	_hideDiv: function() {
		this.div.hide();
	}
}

/*
 * Terminal
 */
var debugWindow = null;
var commandHistory;
var historyIndex;
var konsoleLoginAs = "guest";
var sitehostname = "deskcloud";
var workingDir = "/home/deskcloud";
var deskcloudConsoleWelcome = "<pre>         mm<br />"
	+ "      /^(  )^\\  <br />"
	+ "      \\,(..),/      <br />"
	+ "        V~~V    -deskcloud</pre>"
	+ "Use '<strong>info</strong>' to show this message.<br /><br />";
var deskhost = konsoleLoginAs + "@" + sitehostname + " ~" + workingDir + " $";

function debug(input, command) {
	if (debugWindow == null)
		return;
	var b = "<br />";
	var s = "&nbsp;&nbsp;&nbsp;";
	switch(command) {
		case 'info':
			output = b + deskcloudConsoleWelcome;
		break;
		case 'hostname':
			output = b + sitehostname;
		break;
		case 'whoami':
			output = b + konsoleLoginAs;
		break;
		case 'pwd':
			output = b + workingDir;
		break;
		case 'ls':
			output = b + "Desktop" + s + "Documents" + s + "Downloads" + s + "Music" + s + "Public" + s + "sonia.txt" + s + "Videos";
		break;
		case 'ls -l':
			output = "<pre>total 336"
			+ b + "drwxr-x---  7 deskcloud deskcloud     4096 2011-10-07 04:01 Desktop"
			+ b + "drwxr-x--- 19 deskcloud deskcloud     4096 2011-10-04 07:38 Documents"
			+ b + "drwxr-x---  9 deskcloud deskcloud     4096 2011-10-11 13:43 Downloads"
			+ b + "drwxr-xr-x 12 deskcloud deskcloud     4096 2011-10-01 00:44 Music"
			+ b + "drwxr-xr-x 95 deskcloud deskcloud     4096 2011-09-07 10:13 Public"
			+ b + "-rw-------  1 deskcloud deskcloud     1665 2011-10-01 09:45 deskcloud.txt"
			+ b + "drwxr-x---  7 deskcloud deskcloud     4096 2011-09-07 22:11 Videos</pre>";

		break;
		case 'help':
			output = b + "available commands :"
			+ b + s + "<strong>info</strong> : show Terminal information" + b
			+ b + s + "<strong>hostname</strong> : show <s>or set</s> the system's host name" + b
			+ b + s + "<strong>ls</strong> : list directory contents"
			+ b + s + s + "available options : <strong>-l</strong> ( use a long listing format )" + b
			+ b + s + "<strong>whoami</strong> : print effective userid" + b
			+ b + s + "<strong>pwd</strong> : print name of current/working directory" + b
			+ b + s + "<strong>help</strong> : print this document" + b;
		break;
		case '':
			output = "";
		break;

		default:
			output = b +  ' : command not found';
	}
	$('debug').innerHTML +=  deskhost + output + "<br />";
	// $('debug').innerHTML +=  deskhost + " " + input + "<br />" + output + "<br />";
	debugWindow.getContent().scrollTop=10000; // Far away
}

function hideDebug() {
	if (debugWindow) {
		debugWindow.destroy();
		debugWindow = null;
	}
}

function deskcloudVirtualConsole() {
	if (debugWindow != null) {
		hideDebug();
	}

	if (debugWindow == null) {
		commandHistory = new Array();
		historyIndex = 0;

		debugWindow = new Window('debug_window', {className: 'dialog',width:500, height:400, left:4, minWidth:250, bottom:42, zIndex:1000, opacity:1, showEffect: Element.show, resizable: true, title: "Terminal"})
		cont = " <input id=\"debug_window_command\" type=\"textbox\">";
		debugWindow.getContent().innerHTML = "<style>#debug_window .dialog_content {background: url('images/bg_trans_70.png') repeat 0 0;} #debug_window_command {width:40%; height: 12px; background: transparent url('images/bg_trans_100.png') repeat 0 0; border:none; font-size:10px; color:#FFF;}</style> <div id='debug'>"+deskcloudConsoleWelcome+"</div>" + deskhost + cont;
		Event.observe('debug_window_command', 'mousedown', donothing);
		Event.observe('debug_window_command', 'keypress', evalJS, false);
	}
	debugWindow.show();
}

function donothing(evt){
		Field.activate('debug_window_command');
		return false;
}

function evalJS(evt){
	if(evt.keyCode == Event.KEY_RETURN){
		var js = $F('debug_window_command');
		try{
			var ret = js;
			if(ret != null)
				debug(js, ret);
		}catch(e){
			debug(e);
		}
		$('debug_window_command').value = '';

		Field.activate('debug_window_command');
		commandHistory.push(js);
		historyIndex = 0;
	}

	if(evt.keyCode == Event.KEY_UP){
		if(commandHistory.length > historyIndex){
			historyIndex++;
			var js = commandHistory[commandHistory.length-historyIndex];
			$('debug_window_command').value = js;
			Event.stop(evt);
			Field.activate('debug_window_command');
		}
	}

	if(evt.keyCode == Event.KEY_DOWN){
		if(commandHistory.length >= historyIndex && historyIndex > 1){
			historyIndex--;
			var js = commandHistory[commandHistory.length-historyIndex];
			$('debug_window_command').value = js;
			Event.stop(evt);
			Field.activate('debug_window_command');
		}
	}
}

function clearDebug() {
	if (debugWindow == null)
 		return;
	$('debug').innerHTML = '';
}

// Overide WindowUtilities getPageSize to remove dock height (for maximized windows)
WindowUtilities._oldGetPageSize = WindowUtilities.getPageSize;
WindowUtilities.getPageSize = function() {
	var size = WindowUtilities._oldGetPageSize();
	var dockHeight = $('deskcloud_dock_bottom').getHeight();
	size.pageHeight -= dockHeight;
	size.windowHeight -= dockHeight;
	return size;
};
// Overide Windows minimize to move window inside dock
Object.extend(Windows, {
	// Overide minimize function
	minimize: function(id, event) {
		var win = this.getWindow(id)
		if (win && win.visible) {
			// Hide current window
			win.hide();
			// Create a dock element
			var element = document.createElement("span");
			element.className = "deskcloud_minimized_window";
			element.style.display = "none";
			element.win = win;
			$('deskcloud_dock_bottom').appendChild(element);
			Event.observe(element, "mouseup", Windows.restore);
			$(element).update(win.getTitle());
			new Effect.Appear(element)
		}
		Event.stop(event);
	},
	// Restore function
	restore: function(event) {
		var element = Event.element(event);
		// Show window
		element.win.show();
		//Windows.focus(element.win.getId());
		element.win.toFront();
		// Fade and destroy icon
		new Effect.Fade(element, {afterFinish: function() {element.remove()}})
	}
})
// blur focused window if click on document
Event.observe(document, "click", function(event) {
	var e = Event.element(event);
	var win = e.up(".dialog");
	var dock = e == $('dock') || e.up("#deskcloud_dock_bottom");
	if (!win && !dock && Windows.focusedWindow) {
		Windows.blur(Windows.focusedWindow.getId());
	}
})

// use jQuery.noConflict() when we use jQuery and prototype lib in the same time
jQuery.noConflict();

jQuery(document).ready(function($){

	/*
	 * music player
	 */
	var Playlist = function(instance, playlist, options) {
		var self = this;

		this.instance = instance; // String: To associate specific HTML with this playlist
		this.playlist = playlist; // Array of Objects: The playlist
		this.options = options; // Object: The jPlayer constructor options for this playlist

		this.current = 0;

		this.cssId = {
			jPlayer: "jquery_jplayer_",
			interface: "jp_interface_",
			playlist: "jp_playlist_"
		};
		this.cssSelector = {};

		$.each(this.cssId, function(entity, id) {
			self.cssSelector[entity] = "#" + id + self.instance;
		});

		if(!this.options.cssSelectorAncestor) {
			this.options.cssSelectorAncestor = this.cssSelector.interface;
		}

		$(this.cssSelector.jPlayer).jPlayer(this.options);

		$(this.cssSelector.interface + " .jp-previous").click(function() {
			self.playlistPrev();
			$(this).blur();
			return false;
		});

		$(this.cssSelector.interface + " .jp-next").click(function() {
			self.playlistNext();
			$(this).blur();
			return false;
		});
	};

	Playlist.prototype = {
		displayPlaylist: function() {
			var self = this;
			$(this.cssSelector.playlist + " ul").empty();
			for (i=0; i < this.playlist.length; i++) {
				var listItem = (i === this.playlist.length-1) ? "<li class='jp-playlist-last'>" : "<li>";
				listItem += "<a href='#' id='" + this.cssId.playlist + this.instance + "_item_" + i +"' tabindex='1'>"+ this.playlist[i].name +"</a>";

				// Create links to free media
				if(this.playlist[i].free) {
					var first = true;
					listItem += "<div class='jp-free-media'>(";
					$.each(this.playlist[i], function(property,value) {
						if($.jPlayer.prototype.format[property]) { // Check property is a media format.
							if(first) {
								first = false;
							} else {
								listItem += " | ";
							}
							listItem += "<a id='" + self.cssId.playlist + self.instance + "_item_" + i + "_" + property + "' href='" + value + "' tabindex='1'>" + property + "</a>";
						}
					});
					listItem += ")</span>";
				}

				listItem += "</li>";

				// Associate playlist items with their media
				$(this.cssSelector.playlist + " ul").append(listItem);
				$(this.cssSelector.playlist + "_item_" + i).data("index", i).click(function() {
					var index = $(this).data("index");
					if(self.current !== index) {
						self.playlistChange(index);
					} else {
						$(self.cssSelector.jPlayer).jPlayer("play");
					}
					$(this).blur();
					return false;
				});

				// Disable free media links to force access via right click
				if(this.playlist[i].free) {
					$.each(this.playlist[i], function(property,value) {
						if($.jPlayer.prototype.format[property]) { // Check property is a media format.
							$(self.cssSelector.playlist + "_item_" + i + "_" + property).data("index", i).click(function() {
								var index = $(this).data("index");
								$(self.cssSelector.playlist + "_item_" + index).click();
								$(this).blur();
								return false;
							});
						}
					});
				}
			}
		},
		playlistInit: function(autoplay) {
			if(autoplay) {
				this.playlistChange(this.current);
			} else {
				this.playlistConfig(this.current);
			}
		},
		playlistConfig: function(index) {
			$(this.cssSelector.playlist + "_item_" + this.current).removeClass("jp-playlist-current").parent().removeClass("jp-playlist-current");
			$(this.cssSelector.playlist + "_item_" + index).addClass("jp-playlist-current").parent().addClass("jp-playlist-current");
			this.current = index;
			$(this.cssSelector.jPlayer).jPlayer("setMedia", this.playlist[this.current]);
		},
		playlistChange: function(index) {
			this.playlistConfig(index);
			$(this.cssSelector.jPlayer).jPlayer("play");
		},
		playlistNext: function() {
			var index = (this.current + 1 < this.playlist.length) ? this.current + 1 : 0;
			this.playlistChange(index);
		},
		playlistPrev: function() {
			var index = (this.current - 1 >= 0) ? this.current - 1 : this.playlist.length - 1;
			this.playlistChange(index);
		}
	};

	var audioPlaylist = new Playlist("2", [
		{
			name:"Immediate Music - Serenata Immortale",
			oga:"http://media.cr7.web.id/music/immediate_music_-_serenata_immortale.ogg"
		},
		{
			name:"Globus - Europa",
			oga:"http://media.cr7.web.id/music/globus_-_europa.ogg"
		},
		{
			name:"Clint Mansell - Requiem For a Dream",
			oga:"http://media.cr7.web.id/music/clint_mansell_-_requiem_for_a_dream.ogg"
		}

	], {
		ready: function() {
			audioPlaylist.displayPlaylist();
			audioPlaylist.playlistInit(false); // Parameter is a boolean for autoplay.
		},
		ended: function() {
			audioPlaylist.playlistNext();
		},
		play: function() {
			$(this).jPlayer("pauseOthers");
		},
		swfPath: "js",
		supplied: "oga, mp3"
	});


	$.backstretch("images/background.jpg", {speed: 400}); // this is backstretch background image.

	/*
	 * Other mouse hover and click event goes here
	 */
	$('#deskcloud_inline_top_menu ul ').css({display: "none"}); // Opera Fix
	$('#deskcloud_inline_top_menu li').hover(function(){
		$('ul.the_menu').hide();
		$(this).find('ul:first').css({visibility: "visible",display: "none"}).show(400); },function(){
			$(this).find('ul:first').css({visibility: "hidden"});
	});

	$('a#music-player').click(function () {
		$('#music-player-action').slideToggle('slow');
	});
	//menu slider
	$('div#deskcloud_logo').click(function () {
		$('ul.the_menu').slideToggle('medium');
	});
	$('.the_menu').mouseleave(function() {
		$(this).slideToggle('medium');
	});
});
