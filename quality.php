
<html>
<head>
<title>Air Pollution level</title>
</head>

<body>
<?php
if(isset($_GET['ppm'])){
  $ppm = $_GET['ppm'];
  echo "PPM :". $ppm;
} else {
  echo "failed";
}
echo $_GET['ppm'];
?>

</body>
</html>
