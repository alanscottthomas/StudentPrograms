</!DOCTYPE>
<HTML>
<BODY>
<style>

.move {
  position: absolute;
  top: 26%;
  left: 95%;
  margin: -150px 0 0 -150px;
  width:100px;
  height:100px;
}
.move a {
	color: black; text-shadow: 0 0 10px rgba(255,0,0,100); letter-spacing:1px; text-align:center; 

}

    button {
        text-align: center;
        margin:auto;
        vertical-align: middle;
        padding:32px 32px;
        width:80%;
        height:20%;
        display:block;
        background-color: white;
    }

</style>

<div class = "move">
<a href = "home_page.php">Map Maker Home</a>
</div>

<br />

<?php

//getting session information//
session_start();
if($_POST){
	$stage = $_POST['stage'];
}
else if($_SESSION){
	$stage = $_SESSION["stage"];
}
else{
	echo" header('Location: Creation.php')";
}
$user_id= $_SESSION['user'];
//-------------------//

//setting db connection information//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game_user";
//--------//

//try to connect to db//
$conn = new mysqli($host, $u, $p, $db);
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}
//-------------//


$sql = "UPDATE user_tbl set room = 1 , sword = 0, shield = 0, stage =  " . $stage .  " WHERE user_id = " . $user_id; //update user table


//if statement for if changing levels worked
if ($conn->query($sql) === TRUE) {
    echo "Your level has been changed";
} else {
    echo "Error updating record: " . $conn->error;
}
//-----------//


//change user's health to 100% SQl statement//
$sql6 = "UPDATE user_tbl set health = 100 WHERE user_id = " . $user_id;    ///restore user's health to 100%
		if ($conn->query($sql6) === TRUE) {
			} 
				else {
						echo "Error updating record: " . $conn->error;
					}
//--------------------//
					
//delete from keychain code
$sql = "delete from keychain_tbl where user_id = '$user_id';"; 
//-------------------//

//connect to SQL statement//
if ($conn->query($sql) === TRUE) {
    echo "Your level has been changed";
} else {
    echo "Error updating record: " . $conn->error;
}
//---------------------//


//delete defeated where user id = id
$sql = "delete from defeated_tbl where user_id = '$user_id';";
//--------------------//

//change level sql statement// 
if ($conn->query($sql) === TRUE) {
    echo "Your level has been changed";
} else {
    echo "Error updating record: " . $conn->error;
}
//--------------------//
?>

<?php
$conn->close();      //close the connection to the DB
?>
<br />
</table>
</BODY>
<meta http-equiv="refresh" content="0; url=game_login.php" />
</HTML>