<!DOCTYPE HTML>  
<html>
<head>
</head>
<body>
<h2>Please select the desired value for cooling</h2>
<?php 
$file_name = "cooling";
$path = "/home/pi/git/AirHandlingUnit/_Controls/config/" . $file_name . ".txt";
$file = fopen($path, "r+") or die("Unable to open file");
$data = fread($file,(filesize("cooling.txt") + 1));
$value = NULL;

if (!empty($_POST))
{
	$value = "cooling,";
	$value .= $_POST['input_value'];
	
	$file = fopen($path,"w");
	fwrite($file, $value);
	
	$setting = fopen("settingChanged.txt", "w");
	fwrite($setting, $file_name);
	fclose($setting);
}

if($value !== NULL)
{
	if($_POST['input_value'] > 99)
		$size = sizeof($value) + 2;
	else
		$size = sizeof($value) + 1;
			
	$data = substr($value, 8, $size);
	$data = htmlspecialchars($data);
} else {
	if($pos = strpos($data, 'cooling')){
	$data = substr($data, $pos + 8, (sizeof($data) + 2));
	$data = htmlspecialchars($data);
	} else {
		$data = NULL;
	}
}
?>
<form action=<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?> method="post">
	Value for cooling: <input type="text" name="input_value">
	<font color="red" size="2">*Corrent value: between 0 and 100</font><br>
	<input type="submit" value="Save!">
</form>
<?php if($data !== NULL){ ?>
<h4> Current value: <?php echo $data ?> </h4>
<?php }
fclose($file);
?>	
</body>
</html>