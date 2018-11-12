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
        
        
        $n=(int)val;
        if($n>200)
        {
            echo "<br/> Air quality is poor";
        }
        else
        echo "<br/> Air quality is good";
        $url1=$_SERVER['REQUEST_URI'];
    header("Refresh: 5; URL=$url1");
        
        ?>
         
        
        
    </body>
</html>
