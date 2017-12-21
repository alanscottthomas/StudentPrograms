<!DOCTYPE>
<HTML>
<BODY>
<?php
//variables to store the database connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
//---------------//

//creating a connection to the SQL database//
$conn = new mysqli($host, $u, $p, $db);
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}
//----------------//

//code to delete the selected room from the SQL table//
$cur_room = $_POST['spot'];
echo "hi".$cur_room;
$sql = "DELETE FROM `room_map_tbl` WHERE `room_map_tbl`.`room_id` = ".$cur_room."; ";
mysqli_query($conn, $sql);
//-----------//


$conn->close();
header("Location: stage_creation_2.php");           //once the conn is closed goto creating page
?>
</BODY>
</HTML>