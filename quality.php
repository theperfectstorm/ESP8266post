
<html>
<head>
<title>Air Pollution level</title>
</head>

<body>
<?php
if(isset($_POST['ppm'])){
  $ppm = $_POST['ppm'];
  echo "PPM :". $ppm;
} else {
  echo "failed";
}
echo $_GET['ppm'];
?>


<?php
$myfile = fopen("1.txt", "w") or die("Unable to open file!");
$txt = $ppm;
fwrite($myfile, $txt);
fclose($myfile);
?>


</body>
</html>
