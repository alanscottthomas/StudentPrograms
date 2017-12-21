<!DOCTYPE>
<HTML>
<BODY>
<?php
//the variables that will be assigned a value from POST
$location = $_POST['spot'];
$monster = $_POST['enemy'];
$key = $_POST['key'];
$lock = $_POST['lock'];
$goal = $_POST['goal'];
$sword = $_POST['sword'];
$shield = $_POST['shield'];
//---------------------//

//code to populate the drop down menus//
list($ns,$we,$stage) = explode(",",$location);
echo $ns;
echo nl2br("<br />");
echo $we;
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
//------------------//

//variables to store the database connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
$counter=0;
//-----------//

//creating SQL connection//
$conn = new mysqli($host, $u, $p, $db);
if(! $conn){
	printf("Connection failed: %s\n",$conn->connect_error);
	exit();
}
//------------------//

$counter = 0;

//select from SQL DB to generate the room table//
$sql = "select * from room_map_tbl where stage_id = ".$stage.";";
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
while($row=$result->fetch_assoc()){
		$counter=$row['room_number'];
}
if($goal!=0){
	$color = "purple";
}

else if($sword !=0){
	$color = "orange";
}

else if($shield !=0){
	$color = "pink";
}

else if($monster!=0){
	$color = "red";
}
else if($lock!=0){
	$color = "green";
}
else if($key!=0){
	$color = "yellow";
}
else{
	$color = "blue";
}
echo $color;
//----------------//




echo nl2br("<br />");
echo $counter;
$newroom=$counter+1;
echo nl2br("<br />");
echo $newroom;
echo nl2br("<br />");


//checking if the room has a shield or sword//
if($sword == 0 && $shield == 0)
{
	$sql = "INSERT INTO room_map_tbl (room_id, room_number, stage_id, ns, we, key_id, enemy_id, lock_id, goal, color, sword, shield) VALUES (NULL, '$newroom', '$stage', '$ns', '$we', '$key', '$monster', '$lock', '$goal', '$color', '0', '0');";

if ($conn->query($sql) === TRUE) {
    echo "New Room Created Successfully";
} 
else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
	header("Location: stage_creation_2.php");
}
//

// add sword when making a new room//
else if($sword > 0 && $shield == 0)
{
$sql = "INSERT INTO room_map_tbl (room_id, room_number, stage_id, ns, we, key_id, enemy_id, lock_id, goal, color, sword, shield) VALUES (NULL, '$newroom', '$stage', '$ns', '$we', '$key', '$monster', '$lock', '$goal', '$color', $sword, '0');";

echo "here";
if ($conn->query($sql) === TRUE) {
    echo "New Room Created Successfully";
} 
else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
header("Location: stage_creation_2.php");
}
//---------------//


// add shield when making a new room
else if($sword == 0 && $shield > 0)
{
$sql = "INSERT INTO room_map_tbl (room_id, room_number, stage_id, ns, we, key_id, enemy_id, lock_id, goal, color, sword, shield) VALUES (NULL, '$newroom', '$stage', '$ns', '$we', '$key', '$monster', '$lock', '$goal', '$color', '0', '$shield');";

echo "here";
if ($conn->query($sql) === TRUE) {
    echo "New Room Created Successfully";
} 
else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}
header("Location: stage_creation_2.php");
}
//--------------//



$conn->close();
?>
</BODY>
</HTML>