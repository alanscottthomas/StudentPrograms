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
$resultSet = $mysqli->query("SELECT room_id FROM rooms_tbl WHERE level_name = '$search'");




if($resultSet->num_rows > 0){

    }
     else {
          $output = "No results";
          }

}
?>




<!--ADD ENEMY-->
<form  id="data" class="form-addroom" role="form" method="post" action="addenemy.php">
<fieldset>
<legend>Add Enemy</legend>             
<select name="level_name">
                <option value="">--- Room to add enemy to ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>






<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Add Foe">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</fieldset>
</form>
<!------------------>





<!--ADD START-->
<form  id="data" class="form-addroom" role="form" method="post" action="addstart.php">
<fieldset>
<legend>Which Room Will the Player Start in</legend>             
<select name="level_name">
                <option value="">--- Select Starting Room ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>






<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Add Start">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</fieldset>
</form>
<!------------------>




<!--ADD END-->
<form  id="data" class="form-addroom" role="form" method="post" action="addend.php">
<fieldset>
<legend>Which Room Will the End be Located</legend>             
<select name="level_name">
                <option value="">--- Select End Room ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>






<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Add End">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</fieldset>
</form>
<!------------------>






<!--ADD LOCKED ROOM AND KEY-->
<form  id="data" class="form-addroom" role="form" method="post" action="addlock.php">
<fieldset>
<legend>Lock a Room</legend>             
<select name="level_name">
                <option value="">--- Locked room ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>


<select name="key_room">
                <option value="">--- Room Where This Key is Located ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>





<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Lock Room">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</fieldset>
</form>
<!------------------>









<!--ADD NORTH-->
<form  id="data" class="form-addroom" role="form" method="post" action="addnorth.php">
<fieldset>
<legend>Connect to a Northerly Room</legend>             
<select name="level_name">
                <option value="">--- Origin room ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>


<select name="north_room">
                <option value="">--- Room to the North ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>





<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Connect">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</fieldset>
</form>
<!------------------>





<!--ADD SOUTH-->
<form  id="data" class="form-addroom" role="form" method="post" action="addsouth.php">
 <fieldset>
<legend>Connect to a Southerly Room</legend>            
<select name="level_name">
                <option value="">--- Origin room ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>


<select name="south_room">
                <option value="">--- Room to the South ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>





<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Connect">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</fieldset>
</form>
<!------------------>




<!--ADD WEST-->
<form  id="data" class="form-addroom" role="form" method="post" action="addwest.php">
<fieldset>
<legend>Connect to a Westerly Room</legend>             
<select name="level_name">
                <option value="">--- Origin room ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>


<select name="west_room">
                <option value="">--- Room to the West ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>





<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Connect">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>


</fieldset>
</form>
<!------------------>




<!--ADD EAST-->
<form  id="data" class="form-addroom" role="form" method="post" action="addeast.php">
<fieldset>
<legend>Connect to an Easterly Room</legend>            
<select name="level_name">
                <option value="">--- Origin room ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>


<select name="east_room">
                <option value="">--- Room to the East ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM rooms_tbl where level_name='$search'");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['room_id']."'>".$row['room_id']."</option>";
                       }
                ?>

            </select>





<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="Connect">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>

</fieldset>
</form>
<!------------------>











	</body>

	</html>




<?php echo $output; ?>
