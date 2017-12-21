<!DOCTYPE>
<HTML>
<BODY>
<?php
//the variables that will be assigned a value from POST//
$location = $_POST['spot'];
$monster = $_POST['enemy'];
$key = $_POST['key'];
$lock = $_POST['lock'];
$goal = $_POST['goal'];
$sword = $_POST['sword'];
$shield = $_POST['shield'];
//----------------------------------------//

//code to populate the drop down menus//
list($room,$stage) = explode(",",$location);
echo $room;
echo nl2br("<br />");
echo $stage;
echo nl2br("<br />");
echo $monster;
echo nl2br("<br />");
echo $key;
echo nl2br("<br />");
echo $lock;
echo nl2br("<br />");
echo $goal;
echo nl2br("<br />");

if($goal==1){
	$color = "purple";
}
else if($monster>0){
	$color = "red";
}

else if($sword>0){
	$color = "orange";
}

else if($shield>0){
	$color = "pink";
}

else if($lock>0){
	$color = "green";
}
else if($key>0){
	$color = "yellow";
}
else{
	$color = "blue";
}
echo $color;
//-----------------------------//

//variables to store the database connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
//---------------------//

//creating SQL connection//
$conn = new mysqli($host, $u, $p, $db);
if(! $conn){
	printf("Connection failed: %s\n",$conn->connect_error);
	exit();
}
//----------------//

//statement to update the table//
$sql = "UPDATE room_map_tbl SET key_id = '$key', enemy_id = '$monster', lock_id = '$lock', goal = '$goal', color = '$color', sword = '$sword', shield = '$shield' WHERE room_map_tbl.room_id = '$room'; ";
//----------------//

//execute update//
mysqli_query($conn,$sql);
//--------------//

header("Location: stage_creation_2.php");        //once the update is complete goto creation page
$conn->close();
?>
</BODY>
</HTML>