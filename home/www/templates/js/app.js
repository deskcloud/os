function deskcloud(o, k){
  desktop = new Window({
    className: "mac_os_x",
    title: o,
    width:600,
    height:500,
    url: k,
    hideEffectOptions: {duration:0.5}
  });
  desktop.show();
};

dolphin_to_articles_dir = new Window('Dolphin Articles', {
  className: "mac_os_x",
  title: "Created HTML Element with Javascript",
  width:600,
  height:300,
  top:40,
  left:200,
  hideEffectOptions: {duration:0.3},
  showEffectOptions: {duration:0.5}
});

dolphin_to_articles_dir.getContent().innerHTML =
"<div class=\"dolphin_list dol-large\"><ul class=\"clear\">" +
// you may start looping the list here
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/README.html')\" title=\"Judul\"><img src=\"images/mimetypes/txt.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">text-file.txt</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/py.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">ptyhon-script.py</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/perl.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">perl-script.py</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/php.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">php-script.py</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/zip.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">archive.zip</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/pdf.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">file.pdf</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/txt.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">and so on</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/txt.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">and on and on and on</span></span></li>" +
"<li><a href=\"#\" onclick=\"deskcloud('Title Example','archives/page-example.html')\" title=\"Judul\"><img src=\"images/mimetypes/txt.png\" alt=\"\" class=\"thumb\" /></a><span class=\"title\"><span class=\"wrap\">and on . . . . . . .</span></span></li>" +

"</ul>"+"</div>";

stringtools.showCenter();
