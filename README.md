//CODE TO CONNECT ESP8266 TO SERVER AND PROCESS IT USING PHP
//DEMONSTRATION OF GET/POST METHOD USING ESP8266 WITH ARDUINO
//Eg. update.php?val=70
quality.php : serves post request,creates s new file ("1.txt") and write sensor value (obtained from $_POST['val'])
monitor.php : The main page dislaying data. (reads from 1.txt)
