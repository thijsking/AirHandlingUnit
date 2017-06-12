<!DOCTYPE HTML>  
<html>
<head>
</head>
<body>
<?php 
$file_name = "sensorValues";
$path = "/home/pi/git/AirHandlingUnit/_Controls/config/" . $file_name . ".txt";
$file = fopen($path, "r+") or die("Unable to open file");
$data = fread($file,(filesize("sensorValues.txt") + 1));

$co2 = substr($data, strpos($data, "co2-1") + 6, ((strpos($data, ";", strpos($data, "co2-1")) - strpos($data, "cos 2-1")) - 3)) . " ppm";
//$temperature1 = substr($data, strpos($data, "temperature1") + 6, (strpos($data, ";", strpos($data, "temperature1")) - strpos($data, "temperature1")) - 10) . "degrees";
$temperature2 = substr($data, strpos($data, "temperature2") + 13, (strpos($data, ";", strpos($data, "temperature2")) - strpos($data, "temperature2")) - 10) . " degrees";
$temperature3 = substr($data, strpos($data, "temperature3") + 13, (strpos($data, ";", strpos($data, "temperature3")) - strpos($data, "temperature3")) - 10) . " degrees";
$temperature4 = substr($data, strpos($data, "temperature4") + 13, (strpos($data, ";", strpos($data, "temperature4")) - strpos($data, "temperature4")) - 10) . " degrees";
$temperature5 = substr($data, strpos($data, "temperature5") + 13, (strpos($data, ";", strpos($data, "temperature5")) - strpos($data, "temperature5")) - 10) . " degrees";
$temperature6 = substr($data, strpos($data, "temperature6") + 13, (strpos($data, ";", strpos($data, "temperature6")) - strpos($data, "temperature6")) - 10) . " degrees";
$temperature7 = substr($data, (strpos($data, "temperature7") + 13), (strpos($data, ";", strpos($data, "temperature7")) - strpos($data, "temperature7")) - 10) . " degrees";
//$temperature8 = substr($data, strpos($data, "temperature8") + 6, (strpos($data, ";", strpos($data, "temperature8")) - strpos($data, "temperature8")) - 10) . " degrees";
//$Humidity1 = substr($data, strpos($data, "humidity1") + 10, (strpos($data, ";", strpos($data, "humidity1")) - strpos($data, "humidity1")) - 7) . "%";
$Humidity2 = substr($data, strpos($data, "humidity2") + 10, (strpos($data, ";", strpos($data, "humidity2")) - strpos($data, "humidity2")) - 7) . "%";
$Humidity3 = substr($data, strpos($data, "humidity3") + 10, (strpos($data, ";", strpos($data, "humidity3")) - strpos($data, "humidity3")) - 7) . "%";
$Humidity4 = substr($data, strpos($data, "humidity4") + 10, (strpos($data, ";", strpos($data, "humidity4")) - strpos($data, "humidity4")) - 7) . "%";
$Humidity5 = substr($data, strpos($data, "humidity5") + 10, (strpos($data, ";", strpos($data, "humidity5")) - strpos($data, "humidity5")) - 7) . "%";
$Humidity6 = substr($data, strpos($data, "humidity6") + 10, (strpos($data, ";", strpos($data, "humidity6")) - strpos($data, "humidity6")) - 7) . "%";
$Humidity7 = substr($data, strpos($data, "humidity7") + 10, (strpos($data, ";", strpos($data, "humidity7")) - strpos($data, "humidity7")) - 7) . "%";
//$Humidity8 = substr($data, strpos($data, "humidity8") + 10, (strpos($data, ";", strpos($data, "humidity8")) - strpos($data, "humidity8")) - 7) . "%";
?>
Co2: <?php echo $co2 ?><br><br>
temperature1: Niet aangesloten! <?php //echo $temperature1 ?><br>
temperature2: <?php echo $temperature2 ?><br>
temperature3: <?php echo $temperature3 ?><br>
temperature4: <?php echo $temperature4 ?><br>
temperature5: <?php echo $temperature5 ?><br>
temperature6: <?php echo $temperature6 ?><br>
temperature7: <?php echo $temperature7 ?><br>
temperature8: Niet aangesloten!<?php //echo $temperature8 ?><br><br>
Humidity1: Niet aangesloten!<?php //echo $Humidity1 ?><br>
Humidity2: <?php echo $Humidity2 ?><br>
Humidity3: <?php echo $Humidity3 ?><br>
Humidity4: <?php echo $Humidity4 ?><br>
Humidity5: <?php echo $Humidity5 ?><br>
Humidity6: <?php echo $Humidity6 ?><br>
Humidity7: <?php echo $Humidity7 ?><br>
Humidity8: Niet aangesloten!<?php //echo $Humidity8 ?><br>
</body>
</html>