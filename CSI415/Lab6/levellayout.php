<html>

	<head>

	<title>View Level Layout</title>

	</head>

	<body>
<body style="font-family:Arial;background-color:#F0ECDC;color: #461e72">



<?php
$output = NULL;

if(isset($_POST['submit'])){
//connect to DB
$mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");

$search = $mysqli->real_escape_string($_POST[level_name]);

//query DB
$resultSet = $mysqli->query("SELECT * FROM rooms_tbl WHERE level_name = '$search'");


if($resultSet->num_rows > 0){
echo '<table align="left"
    cellspacing="5" cellpadding="8">

    
    <td align="left"><b>RoomID</b></td>    
 <td align="left"><b>Level_name</b></td>   
 <td align="left"><b>North</b></td>
    <td align="left"><b>South</b></td>
    <td align="left"><b>West</b></td>
    <td align="left"><b>East</b></td>
    <td align="left"><b>Enemy</b></td>
    <td align="left"><b>Key</b></td>
    <td align="left"><b>Key Goes to Room</b></td>
    <td align="left"><b>Locked</b></td>
    <td align="left"><b>Start</b></td>
    <td align="left"><b>End</b></td>';



    while($rows = mysqli_fetch_array($resultSet))
      {
          
          //$rows2= mysqli_fetch_array($resultSet2);
          echo '<tr><td align="center">'.
          $room_id = $rows['room_id'].'</td><td align="center">'.
          $level_name = $rows['level_name'].'</td><td align="center">'.
          $north = $rows['north'].'</td><td align="center">'.
          $south = $rows['south'].'</td><td align="center">'.
          $west = $rows['west'].'</td><td align="center">'.
          $east = $rows['east'].'</td><td align="center">';

          $enemy = $mysqli->query("SELECT enemy FROM contents_tbl WHERE (room_id='$room_id') and (enemy is not null)");
          $enemy_val = mysqli_fetch_array($enemy);
          
          $key = $mysqli->query("SELECT key_ FROM contents_tbl WHERE (room_id='$room_id') and  (key_ is not null)");
          $key_val = mysqli_fetch_array($key);

          $key_to_room = $mysqli->query("SELECT key_to_room FROM contents_tbl WHERE (room_id='$room_id') and  (key_to_room is not null)");
          $key_to_room_val = mysqli_fetch_array($key_to_room);


 $chest = $mysqli->query("SELECT chest FROM contents_tbl WHERE (room_id='$room_id') and (chest is not null)");
          $chest_val = mysqli_fetch_array($chest);


         $start = $mysqli->query("SELECT start FROM contents_tbl WHERE (room_id='$room_id') and  (start is not null)");
          $start_val = mysqli_fetch_array($start);


$end = $mysqli->query("SELECT end FROM contents_tbl WHERE (room_id='$room_id') and  (end is not null)");
          $end_val = mysqli_fetch_array($end);

          



echo $enemy_print=$enemy_val['enemy'].'</td><td align="center">'.
               $key_print=$key_val['key_'].'</td><td align="center">'.
               $key_to_room_print=$key_to_room_val['key_to_room'].'</td><td align="center">'.
               $chest_print=$chest_val['chest'].'</td><td align="center">'.
               $start_print=$start_val['start'].'</td><td align="center">'.
               $end_print=$end_val['end'].'</td><td align="center">';
          
          
         
          
 

          
          
         

echo '</tr>';

 
      }
    echo '</table>';
    }
     else {
          $output = "No results";
          }

}
?>

<form  id="data" class="form-addroom" role="form" method="post" action="levellayout.php">
            <select name="level_name">
                <option value="">--- Select ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM levels_tbl");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['level_name']."'>".$row['level_name']."</option>";
                       }
                ?>

            </select>




<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Level layout">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</form>

	</body>

	</html>




<?php echo $output; ?>
