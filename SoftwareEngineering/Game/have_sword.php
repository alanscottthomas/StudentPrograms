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
//start php session//
session_start();
//----------//

//assign variables from session//
$enemy = $_SESSION["enemynum"];
$id = $_SESSION["id"];
$_SESSION["id"] = $id;
$defeated = $_SESSION["defeated"];
$newroom = $_SESSION["newroom"];
$stage = $_SESSION["stage"];
$_SESSION["stage"] = $stage;

//set DB connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
$db2 = "game_user";
//----------//


$enemyname;
$enemytype;

header('Location: run_game.php');       //take user to run game page 
	
$conn2->close();   //close the SQL connection

?>
</div>
		</BODY>
</HTML>