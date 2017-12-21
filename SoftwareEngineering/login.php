<!DOCTYPE>
<HTML>
<HEAD><TITLE>Logging in</TITLE></HEAD>
<BODY>
<?php
//variables to store the database connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
//----------//

//the variables that will be assigned a value from POST
$user = $_POST['u'];
$pw = $_POST['p'];
//-------------//

//code to check if username and password are a match
echo $user .nl2br("<br />"). $pw ;
if ($user&&$pw){
	//creating conn for the SQL database
	$conn = new mysqli($host, $u, $p, $db);
	
	//if the connection cannot be established display an error
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}
	//gathering username and password from DB to conduct a compare
	$sql = "select * from login_tbl where username = '".$user."';";
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
	while ($row = $result->fetch_assoc()){
		//if user and pw are a match goto the home page
		if($user == $row['username']){
			if($pw == $row['password']){
				header( "Location: home_page.php");
			}
		}
	}
}
//-------------------------//

//if the username and password are incorrect do not continue
echo nl2br("<br />")."Incorrect combination of username and password ";
header( "Location: game.php" );
//----------//

$conn.close();                    //close the connection
?>
</BODY>
</HTML>
