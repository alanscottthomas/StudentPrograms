<body style="font-family:Arial;background-color:#F0ECDC;color: #461e72">
<form  id="data" class="form-addroom" role="form" method="post" action="selectroom.php">
<fieldset>
<legend>Select your level</legend>              
 <select name="level_name">
                <option value="">--- Select your level ---</option>
                <?php 
                    $mysqli =NEW MySQLi("localhost","root","password123","lab5_db1");
                    $result=$mysqli->query("SELECT * FROM levels_tbl");
                    while ($row = mysqli_fetch_array($result)) {
                     echo "<option value='".$row['level_name']."'>".$row['level_name']."</option>";
                       }
                ?>

            </select>

<p>
        <input type="submit" name="submit" style="font-family: 'Arial'; font-size: larger; color: #ffffff;border-radius:12px; background-color: #29104C; border: 3pt solid #7B4FA5" value="The level your room is on">
	<!--<input type="submit" name="submit" value="Send" /> -->

	</p>
</fieldset>
</form>














