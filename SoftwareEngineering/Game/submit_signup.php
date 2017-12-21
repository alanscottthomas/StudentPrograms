<!DOCTYPE>
<HTML>
<HEAD><TITLE>Logging in</TITLE></HEAD>
<BODY>
<?php
//set db connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game_user";
//--------------//

//set user and pw to post data//
$user = $_POST['u'];
$pw = $_POST['p'];
$test=0;
//----------//

//if user and pw entered do this..//
if ($user&&$pw){
	$conn = new mysqli($host, $u, $p, $db);                                  //create sql connection
	//if cant connect to db//
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}
	//---------//
	$sql = "select * from login_tbl;";                                       //select from login table
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");    //place login data into results
	
	//while to sort through usernames//
	while ($row = $result->fetch_assoc()){
		if($user == $row['username']){
			$test = 1;
			echo $test;
			header("Location: dead.php");
		}
	}
	//------------------//
	$conn->close();          //close sql connection
}
$id=0;

//if test is 0//
if($test == 0){
$conn = new mysqli($host, $u, $p, $db);         //connect to sql db
//if failed to connect//
if(! $conn){
	printf("Connection failed: %s\n",$conn->connect_error);
	exit();
}
//---------//

$sql = "INSERT INTO `login_tbl` (`username`,`password`) VALUES ('$user','$pw');";           //insert user's name and pw into login table
mysqli_query($conn, $sql);                                                                  //execute sql statement
$sql = "select * from login_tbl where username = '".$user."';";                             //select from login table where user name matches user
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");                   //place login data into results
	//sort through login details
	while ($row = $result->fetch_assoc()){
		$id = $row['user_id'];     //set id to user id
	}
	//-------//
$sql = "INSERT INTO user_tbl (user_id, room, stage, health) VALUES ('$id','1','1','100');";    //set default values for a new player
mysqli_query($conn, $sql);          //execute sql statement
$conn->close();                     //close sql connection
header("Location: game_login.php"); //send user to game login
}
?>
</BODY>
</HTML>