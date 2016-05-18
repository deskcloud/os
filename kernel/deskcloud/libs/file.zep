namespace Deskcloud\Libs;

class File {

      public static function create(string! location, string! content) {
      var file, dir;
      let dir = dirname($_GET["_url"]);
      let file = fopen(dir."/".location,"w");
      fwrite(file, content);
      fclose(file);
      }

      public static function read(string! location) {
      var dir;
      let dir = dirname($_GET["_url"]);
      return file_get_contents(dir."/".location, true);
      }

      public static function extension(string! location) {
      var dir;
      let dir = dirname($_GET["_url"]);
      return pathinfo(dir."/".location, PATHINFO_EXTENSION);
      }

      public static function time(string! format, string! location) {
      var dir;
      let dir = dirname($_GET["_url"]);
      return date(format, filemtime(dir."/".location));
      }

      public static function copy(string! location, string! newlocation) {
      var dir;
      let dir = dirname($_GET["_url"]);
      if (!copy(dir."/".location, dir."/".newlocation)) {
        echo "failed to copy...\n";
      }
      }

      public static function rename(string! location, string! newname) {
      var dir;
      let dir = dirname($_GET["_url"]);
      if (!rename(dir."/".location, dir."/".newname)) {
      	echo "failed to rename...\n";
      }
      }

      public static function delete(string! location) {
      var dir;
      let dir = dirname($_GET["_url"]);
      if (!unlink(dir."/".location)) {
      	echo "failed to delete...\n";
      }
      }

      public static function size(string! location, format = false) {
      var size, base, dir;
      let dir = dirname($_GET["_url"]);
      if(format == true){
          array type;
          let type = [" bytes", " KB", " MB", " GB", " TB"];
      	  let size = filesize(dir."/".location);
          let base = log(size, 1024);
              if(base > 0){
                  return round(pow(1024, base - floor(base)), 2) . type[base];
                  }else{
                  return "0 bytes";
              }
          }else{
              return filesize(dir."/".location);
          }
		}
}
