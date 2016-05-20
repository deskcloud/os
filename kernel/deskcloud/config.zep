namespace Deskcloud;

class Config {

        private static function config(location, section, config)
        {
              var setting;
              if(file_exists(location)){
                  let setting = parse_ini_file(location,true);
                  if(isset(setting[section][config])){
                      return setting[section][config];
                  }else{
                      return "none";
                  }
              }else{
                  return "none";
              }
        }

}
