<!DOCTYPE HTML>  
<html>
<head>
</head>
<body>
<h2>Please select the desired mode</h2>

<?php
#/home/pi/git/AirHandlingUnit/_Controls/config/mode.txt
$file_name = "mode";
$path = "/home/pi/git/AirHandlingUnit/_Controls/config/" . $file_name . ".txt";
$file = fopen($path, "r+") or die("Unable to open file");
$data = fread($file,(filesize("mode.txt") + 1));
$operation_mode = NULL;
$value = NULL;

if (!empty($_POST))
{
	switch($_POST['Mode']) {
        case "Manual":
			$operation_mode = "manual";
			break;
		case "Automatic":
			$operation_mode = "automatic";
			break;
	}
	
	$file = fopen($path,"w");
	fwrite($file, $operation_mode);
	
	$setting = fopen("settingChanged.txt", "w");
	fwrite($setting, $file_name);
	fclose($setting);
}

if($value !== NULL) {
	$data = $operation_mode;
} else {
	if(empty($data)){
		$data = NULL;
	}
}
?>
<form action=<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?> method="post">
	<input type="radio" name="Mode" value="Manual">Manual
	<input type="radio" name="Mode" value="Automatic" disabled=disabled>Automatic<br><br>
	<input type="submit" value="Save!">
</form>
<?php if($data !== NULL){ ?>
<h4> Current value: <?php echo $data ?> </h4>
<?php }
fclose($file);
?>	
</body>
</html>