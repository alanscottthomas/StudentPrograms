<!DOCTYPE>
<HTML>
<HEAD>	
</HEAD>
<BODY>
<div style="text-align:center">
	<body style="background-color:black;">
		<font color="white">
			Incorrect username or password</font>
		</div>
		
<?php
//start php session//
session_start();
//----------//

//set db connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game_user";
//----------//

//set name and pw to post data//
$user = $_POST['u'];
$pw = $_POST['p'];
//-----------//


//check username and password against info in db//
if ($user&&$pw){
	$conn = new mysqli($host, $u, $p, $db);                                //connect to sql db
	//if user can't connect to the db...//
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}
	//----------//
	
	$sql = "select * from login_tbl where username = '".$user."';";         //select from login table
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");   //save data to results
	//place results in rows
	while ($row = $result->fetch_assoc()){
		//check if name matches..//
		if($user == $row['username']){
			//check if password matches..//
			if($pw == $row['password']){
				$_SESSION["id"] = $row['user_id'];     //set id to user id
				$_SESSION["user"]=$user;               //set user to user name
				echo $_SESSION["user"];
				$conn->close();                       //close connection
				header( "Location: run_game.php");     //move user to run game page
			}
		}
	}
}
//if the username or pw is wrong//
else{
	echo nl2br("<br />")."Incorrect combination of username and password ";
	header( "Location: Game/login.php" );
}
//--------//

$conn->close();          //close connection to db
?>
</BODY>
</HTML>
