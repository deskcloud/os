namespace Deskcloud\Libs;

class Time {

      public static function now(timezone = "Asia/Jakarta") {
            date_default_timezone_set(timezone);
            var time;
            let time = Time();
            let time = date("h:i A", time);
            return time;
      }

}
