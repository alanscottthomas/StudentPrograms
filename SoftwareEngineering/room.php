<!DOCTYPE>
<HTML>
<BODY>
	<BODY>
	<body style="background-color:black;">
		<font color="white">
<?php
session_start();   //starting a new session

//variables to store the session info//
$stage=$_SESSION["stage"];
$room=0;
$counter = 0;
$location = $_POST['spot'];
//-----------//

echo nl2br("<br />");


list($we,$ns,$stage) = explode(",",$location);     //listing options for N,W,S,E
echo nl2br("<br />");

//setting variables for DB connection//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
//------------------//

//try to create a connection to the DB
$conn = new mysqli($host, $u, $p, $db);
if(! $conn){
	printf("Connection failed: %s\n",$conn->connect_error);
	exit();
}
//------------------//

//pulling stage info from the DB//
$sql = "select * from stage_tbl";
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
while($row=$result->fetch_assoc()){
	$counter++;
}
//--------------------------------//


//pulling the variables that have been assigned to a room//
$sql = "select * from room_map_tbl where stage_id = ".$stage.";";
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
while($row=$result->fetch_assoc()){
	if($we==$row['we']&&$ns==$row['ns']){
		$room = $row['room_id'];        //get room ID
		$monster = $row['enemy_id'];    //add enemy
		$key = $row['key_id'];          //add key
		$lock = $row['lock_id'];        //add lock
		$goal = $row['goal'];           //add goal
		$sword = $row['sword'];        //add sword to room map table
		$shield = $row['shield'];      //add shield
	}
}
//------------------------------------------//


//if statements to determine what option the user made//
if($room!=0){
	$cur_room = $room;
	echo nl2br("<br />");
	echo "Current Room being edited: ".$cur_room. nl2br("<br />")."Current Stage: ".$stage;
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo "Would you like to delete this room? ";
	echo "<form action = 'delete_room.php' method = 'post'>";
	echo "<button name='spot' type='submit' value='".$cur_room."'>Delete Room: ".$cur_room."</button>";
	echo "</form>";
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo nl2br("<br />");
	if($goal == 1){              //set room as a goal
		$answer = "Yes";
	}
	else{
		$answer = "No";
	}
	echo "Is room a Goal?: ".$answer;
    echo nl2br("<br />");
    if($monster > 0 ){           //set room to have an enemy
    	$answer2 = "Monster";
    }
    else{
    	$answer2 = "No Monster";
    }
    echo "Monster number: ".$answer2;
    echo nl2br("<br />");
    echo "Key number: ". $key;
    echo nl2br("<br />");
    echo "Lock number: ". $lock;
    echo nl2br("<br />");
    echo nl2br("<br />");
    echo "Whatever the key number is, that is what lock number it opens.";
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo "Options for editing room.";
	echo nl2br("<br />");
	echo nl2br("<br />");
	
	echo str_repeat('&nbsp;', 10);
	echo "enemy";
	echo str_repeat('&nbsp;', 20);
	echo "sword";
	echo str_repeat('&nbsp;', 15);
	echo "shield";
	echo str_repeat('&nbsp;', 20);
	echo "key";
	echo str_repeat('&nbsp;', 25);
	echo "lock";
	echo str_repeat('&nbsp;', 20);
	echo "goal";
	
	
	
	echo nl2br("<br />");
	//dropdown for enemy//
	echo "<form action = 'edit_room.php' method = 'post'>";
	echo "<select name = 'enemy'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$monster."'>Don't Change</option>";
	echo "<option value = '0'>no monster</option>";
	$sql = "SELECT * FROM `enemy_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$monsternum = $row['enemy_id'];
		$enemyname = $row['name'];
		$enemytype = $row['difficulty'];
		if($monster != $monsternum){
		echo "<option value = '".$monsternum."'>".$enemyname." the ".$enemytype."</option>";
		}
	}
	echo "</select>";
	//-------------------------//
	
	//sword dropdown//
	echo "<select name = 'sword'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$sword."'>Don't Change</option>";
	echo "<option value = '0'>no sword</option>";
	$sql = "SELECT * FROM `sword_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$swordnum = $row['sword_id'];
		if($swordnum!=$sword){
		echo "<option value = '".$swordnum."'>Exaclibur</option>";
		}
	}
	echo "</select>";
	//-------------//
	
	
	
	//shield dropdown//
	echo "<select name = 'shield'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$shield."'>Don't Change</option>";
	echo "<option value = '0'>no shield</option>";
	$sql = "SELECT * FROM `shield_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$shieldnum = $row['shield_id'];
		if($shieldnum!=$shield){
		echo "<option value = '".$shieldnum."'>Pridwen</option>";
		}
	}
	echo "</select>";
	//-------------//
	
	
	//key drowndown menu//
	echo "<select name = 'key'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$key."'>Don't Change</option>";
	echo "<option value = '0'>no key</option>";
	$sql = "SELECT * FROM `key_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$keynum = $row['key_id'];
		if($keynum!=$key){
		echo "<option value = '".$keynum."'>Key Number: ".$keynum."</option>";
		}
	}
	echo "</select>";
//-----------------------------//

	//lock dropwdown//
	echo "<select name = 'lock'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$lock."'>Don't Change</option>";
	echo "<option value = '0'>no lock</option>";
	$sql = "SELECT * FROM `lock_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$locknum = $row['lock_id'];
		if($locknum!=$lock){
		echo "<option value = '".$locknum."'>Lock Number: ".$locknum."</option>";
		}
	}
	echo "</select>";
	//------------------//
	
	
//goal dropdown//
	echo "<select name = 'goal'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$goal."'>Don't Change</option>";
	echo "<option value = '0'>no goal</option>";
	echo "<option value = '1'>goal</option>";
	echo "</select>";
	//------------//
	
	echo "<button name='spot' type='submit' value='".$room.",".$stage."'>Submit edit</button>";   //submit button
}
else{
	
	//text at the top of the page//
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo "Whatever the key number is that is what lock number it opens.";
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo nl2br("<br />");
	echo "Select options for adding a room.";
	echo nl2br("<br />");
	echo nl2br("<br />");
	//--------------------//
	
	//fill dropdown menus with options//
	echo str_repeat('&nbsp;', 10);
	echo "enemy";
	echo str_repeat('&nbsp;', 20);
	echo "sword";
	echo str_repeat('&nbsp;', 15);
	echo "shield";
	echo str_repeat('&nbsp;', 20);
	echo "key";
	echo str_repeat('&nbsp;', 25);
	echo "lock";
	echo str_repeat('&nbsp;', 15);
	echo "goal";
	//-------------------//
	
	
	//add room options//
	echo "<form action = 'add_room.php' method = 'post'>";
	echo "<form action = 'edit_room.php' method = 'post'>";
	echo "<select name = 'enemy'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '0'>no monster</option>";
	$sql = "SELECT * FROM `enemy_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$monsternum = $row['enemy_id'];
		$enemyname = $row['name'];
		$enemytype = $row['difficulty'];
		echo "<option value = '".$monsternum."'>".$enemyname." the ".$enemytype."</option>";
	}
	echo "</select>";
	//----------------//
	
	
	
	//sword dropdown//
	echo "<select name = 'sword'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$sword."'>Don't Change</option>";
	echo "<option value = '0'>no sword</option>";
	$sql = "SELECT * FROM `sword_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$swordnum = $row['sword_id'];
		if($swordnum!=$sword){
		echo "<option value = '".$swordnum."'>Exaclibur</option>";
		}
	}
	echo "</select>";
	//-------------//
	
	
	//shield dropdown//
	echo "<select name = 'shield'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '".$shield."'>Don't Change</option>";
	echo "<option value = '0'>no shield</option>";
	$sql = "SELECT * FROM `shield_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$shieldnum = $row['shield_id'];
		if($shieldnum!=$shield){
		echo "<option value = '".$shieldnum."'>Pridwen</option>";
		}
	}
	echo "</select>";
	//-------------//
	
	
	
	//key dropdown//
	echo "<select name = 'key'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '0'>no key</option>";
	$sql = "SELECT * FROM `key_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$keynum = $row['key_id'];
		echo "<option value = '".$keynum."'>Key Number: ".$keynum."</option>";
	}
	echo "</select>";
	//------------------//
	
	
	//lock dropdown//
	echo "<select name = 'lock'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '0'>no lock</option>";
	$sql = "SELECT * FROM `lock_tbl`;";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while($row=$result->fetch_assoc()){
		$locknum = $row['lock_id'];
		echo "<option value = '".$locknum."'>Lock Number: ".$locknum."</option>";
	}
	echo "</select>";
	//------------------//
	
	
	//goal dropdown//
	echo "<select name = 'goal'>";
	//for($i=0;$i<=$counter;$i++){
	echo "<option value = '0'>no goal</option>";
	echo "<option value = '1'>goal</option>";
	echo "</select>";
	//--------------//
	
	echo "<button name='spot' type='submit' value='".$ns.",".$we.",".$stage."'>Submit addition</button>";  //submit button
}
$conn->close();     //close connection to the DB
?>
</BODY>
</HTML>
