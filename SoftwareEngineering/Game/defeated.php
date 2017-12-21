<!DOCTYPE>
<HTML>
<HEAD><TITLE>FIGHT!!</TITLE>
<STYLE>
.move {
  position: absolute;
  top: 35%;
  left: 70%;
  margin: -150px 0 0 -150px;
  width:200px;
  height:100px;
}
.move a {
	color: #FBB03B; text-shadow: 0 0 0px rgba(251,176,59,100); letter-spacing:1px; text-align:center; 

}
</STYLE>
</HEAD>
<BODY>
	<body style="background-color:black;">
		<font color="white">
<?php
//start the PHP session//
session_start();
//----------------//

//code to check if there's an enemy in the room//
if($_SESSION["enemynum"] == NULL)
{
		$enemy=0;
}
	else
	{
		$enemy = $_SESSION["enemynum"];
	}
//--------------------//

//setting variables to the sessions that were passed//
$id = $_SESSION["id"];
$_SESSION["id"] = $id;
//--------------------//

//checking if the enemy has been defeated//
if($_SESSION["defeated"] == NULL)
{
	$defeated = 0;
}

else{
	$defeated = $_SESSION["defeated"];
}
//-----------------------//

//setting additional variables to the data passed from the session//
$newroom = $_SESSION["newroom"];
$stage = $_SESSION["stage"];
$_SESSION["stage"] = $stage;
//----------------------//

//setting the DB information//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
$db2 = "game_user";
//------------------//

$enemyname;
$enemytype;

//try to connect to the DB//
$conn1 = new mysqli($host, $u, $p, $db);
if(! $conn1){
	printf("Connection failed: %s\n",$conn1->connect_error);
	exit();
}
//--------------------//


$sql1 = "SELECT * FROM `enemy_tbl` WHERE `enemy_id` = ".$enemy.";";         //select from enemy table

$result1 = $conn1->query($sql1) or trigger_error($conn1->error."[$sql1]");   //saving enemy data to results

//placing results in rows//
while($row1 = $result1->fetch_assoc()){
	$enemyname = $row1['name'];
	$enemytype = $row1['difficulty'];
}
//-----------//

$conn1->close();   //close connection to DB1

//try to connect to user database
$conn2 = new mysqli($host,$u,$p,$db2);
if(! $conn2){
	prinf("Connection failed: %s\n",$conn2->connect_error);
	exit();
}
//------------//


//get health info//
$sql3 = "SELECT * FROM `user_tbl` WHERE `user_id` = ".$id.";";               //sql statement to pull user data

$result3 = $conn2->query($sql3) or trigger_error($conn2->error."[$sql3]");   //saving data to results

//placing results into rows//
while($row1 = $result3->fetch_assoc()){
	$health = $row1['health'];
	$sword = $row1['sword'];
	$shield = $row1['shield'];
}
//---------//
	
	echo nl2br("<br />");

	$sql2 = "UPDATE `user_tbl` SET `room` = '".$newroom."' WHERE `user_tbl`.`user_id` = ".$id.";";  //update user table
	mysqli_query($conn2, $sql2);    //execute the SQL statement
	echo "<div class = 'move'>";
	echo "</div>";

	
	$sql4 = "UPDATE user_tbl SET health = '$health' WHERE user_tbl.user_id = '$id';";    //update user table
		mysqli_query($conn2, $sql4);           //execute SQL statement
	header('Location: run_game.php');         //send user to the run game page when done  
	
	$conn2->close();                        //close the connection to the DB
?>
</div>
		</BODY>
</HTML>