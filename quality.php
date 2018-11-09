
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

</body>
</html>
