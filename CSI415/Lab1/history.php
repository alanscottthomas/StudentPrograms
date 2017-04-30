<?php echo '<table align="left"
    cellspacing="5" cellpadding="8">

    
    <td align="left"><b>Train</b></td>    
    <td align="left"><b>Stop</b></td>
    <td align="left"><b>Time Of Arrival(H.M.S)</b></td>';

?>



<?php
$output = NULL;
$ran=false;



if(isset($_POST['submit'])){
//connect to DB
$mysqli =NEW MySQLi("localhost","root","password123","choochoo");

$search = $mysqli->real_escape_string($_POST['trainform']);

//query DB
$resultSet = $mysqli->query("SELECT * FROM history_tbl WHERE name LIKE '$search%'");





if($resultSet->num_rows > 0){




    
while($row =mysqli_fetch_array($resultSet))
      {
          
 

        echo '<tr><td align="center">'.
       $row['name'] . '</td><td align="center">'.
       $row['location'] . '</td><td align="center">'.
       $row['arrival'] . '</td><td align="center">';
       
echo '</tr>';
          
          

          //$output .= "$name  $arrival  $location </br></br>" ;
         
      }
    
    }

}
?>
<html>
<b>Select a train to view the history</b>



<body style="font-family:Arial;background-color:rgba(0, 37, 60, .35); color: #FFFFFF ;padding: 10px 100px; border-radius: 1px"> 
 
<!-- <style>indent{padding-left: 10.8em }</style> -->


<p>

<!--<form action="new_search.php">    -->
<form method="POST">
<select name="trainform">
<option value=" "> </option>
<option value="A">A</option>
<option value="B">B</option>
<option value="C">C</option>
</select>

<input type="submit" name="submit">
</br></br>

</form>
<body>
</p>
</html>


<?php echo $output; ?>

