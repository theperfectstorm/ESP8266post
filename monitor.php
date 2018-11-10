<html>
    <head>
        <title>Air Quality Manager</title>
    </head>
    <body>
        <?php
        $myfile = fopen("1.txt", "r") or die("Unable to open file");
        $val= fread($myfile,filesize("1.txt"));
        fclose($myfile);
        echo "<h2>PPM Value : $val </h2><br/>";
        ?>
        
        
        
        
    </body>
</html>
