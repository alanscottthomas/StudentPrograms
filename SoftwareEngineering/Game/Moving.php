<!DOCTYPE>
<HTML>
<BODY>
<?php
//start php session//
session_start();
//---------//

//assign id to session value
$id = $_SESSION["id"];
//

//initialize variables//
$ns = 0;
$we = 0;
$enemy = 0;
$defeated = 0;
//--------//

//assign variables to session values//
$room = $_SESSION["room"];
$stage = $_SESSION["stage"];
$_SESSION["stage"] = $stage;
$_SESSION["room"] = $room;
$_SESSION["id"] = $id;
$user = $_SESSION["user"];
$_SESSION["user"];
//---------//

//set db connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
$db2 = "game_user";
//---------//

//try to connect to game db//
$conn1 = new mysqli($host, $u, $p, $db);
if(! $conn1){
	printf("Connection failed: %s\n",$conn1->connect_error);
	exit();
}
//-----------//

//try to connect to user db//
$conn2 = new mysqli($host,$u,$p,$db2);
if(! $conn2){
	prinf("Connection failed: %s\n",$conn2->connect_error);
	exit();
}
//--------//

//determining the direction that the user can move//
if($_POST['dir']=="north"){
	echo"north";
	echo nl2br("<br />");
	$ns++;
}
else if($_POST['dir']=="south"){
	echo"south";
	echo nl2br("<br />");
	$ns--;
}
else if($_POST['dir']=="west"){
	echo"west";
	echo nl2br("<br />");
	$we--;
}
else if($_POST['dir']=="east"){
	echo"east";
	echo nl2br("<br />");
	$we++;
}
else if($_POST['dir']=="quit"){
	echo"quit";
	echo nl2br("<br />");
	$conn1->close();
	$conn2->close();
	header("Location:/thedepths/home_page.php");
}
else{
	echo "Nothing was submitted. You're a bad person for trying to break my game.";
}
//---------------//

$sql1 = "SELECT * FROM `room_map_tbl` WHERE `room_number` = ".$room." AND `stage_id` = ".$stage.";";    //select room info
$result1 = $conn1->query($sql1) or trigger_error($conn1->error."[$sql1]");                              //save room info to results
$cur_ns=11;
$cur_we=11;
//place room info into rows//
while ($row = $result1->fetch_assoc()){
	$cur_ns=$row['ns'];
	$cur_we=$row['we'];
	if($row['enemy_id']>0){
		$enemy = $row['enemy_id'];
	}
}
//---------//
$cur_ns+=$ns;
echo "ns ".$cur_ns;
echo nl2br("<br />");
$cur_we+=$we;
echo "we ".$cur_we;
echo nl2br("<br />");
$haskey=0;


$sql1 = "SELECT * FROM room_map_tbl WHERE stage_id = '$stage' AND ns = '$cur_ns' AND we = '$cur_we';";  //select room info
$result1 = $conn1->query($sql1) or trigger_error($conn1->error."[$sql1]");                              //save info to results
$newroom=0;

//place room info into the results
while ($row = $result1->fetch_assoc()){
	$lock = $row['lock_id'];           //set lock to lock info from db
	$newroom = $row['room_number'];    //set room to room number from db
	$_SESSION["newroom"] = $newroom;   //set sesstion to newroom 
	$_SESSION["id"] = $id;             //set session id to id

	$enemy = $row['enemy_id'];         //set enemy to enemy data from db
	$sword = $row['sword'];            //set sword to sword data from db
	$shield = $row['shield'];          //set shield to shield data from db
	//if the room is a goal
	if($row['goal'] == 1){
		//close connections//
		$conn1->close();
		$conn2->close();
		//----------//
		header("Location: goal.php");  //send user to goal page
	}
	//---------//
	 //Check if room has a sword//
	else if($sword != 0)
	{
		//if statement to check if the user has a sword in the table
			//if user has a sword goto run_game.php
			$sql2 = "SELECT * FROM user_tbl WHERE user_id = '$id';";
			$result2 = $conn2->query($sql2) or trigger_error($conn2->error."[$sql2]");
			

		//search for a sword
		while($row2 = $result2->fetch_assoc()){
			$sword = $row2['sword'];
			
			//user has sword
			if($sword > 0){
				header("Location: defeated.php"); 
			}
			
			//user doesnt have sword
			else if($sword == 0){
				header("Location: get_sword.php"); // update user to get sword
			}	
		}		
	}
	 //----------------------//
	 
	 
	 
	 
	  //Check if room has a shield//
	else if($shield != 0)
	{
		//if statement to check if the user has a sword in the table
			//if user has a sword goto run_game.php
			$sql2 = "SELECT * FROM user_tbl WHERE user_id = '$id';";
			$result2 = $conn2->query($sql2) or trigger_error($conn2->error."[$sql2]");
			

		//search for a sword
		while($row2 = $result2->fetch_assoc()){
			$shield = $row2['shield'];
			
			//user has sword
			if($shield > 0){
				header("Location: defeated.php"); 
			}
			
			//user doesnt have sword
			else if($shield == 0){
				header("Location: get_shield.php"); // update user to get sword
			}
		
		}
	}
	 //----------------------//
	 
	 
	 
	
	//if the room has an enemy//
	else if($enemy>0){
		echo "enemy is here";
		echo nl2br("<br />");
		//check user defeated table//
		$sql2 = "SELECT * FROM `defeated_tbl` WHERE `stage` = ".$stage." AND `user_id` = ".$id." ;"; //select data from defeated table
		$result2 = $conn2->query($sql2) or trigger_error($conn2->error."[$sql2]");                   //place data into results
		//move data into rows//
		while($row2 = $result2->fetch_assoc()){
			echo "inside enemy while";
			echo nl2br("<br />");
			if($row2['enemy_id']==$enemy){
				$defeated = $row2['enemy_id'];      //set defeated to enemy id
				echo $defeated."   ".$enemy;
					echo "defeated = enemy";
					echo nl2br("<br />");
					//set session variables to enemy and defeated info//
					$_SESSION["defeated"] = $defeated;				
					$_SESSION["enemynum"] = $enemy;
					//----//
					echo "Enemy has been defeated number is".$defeated;
					echo nl2br("<br />");
					echo "This the enemy that has already been faught".$enemy;
					echo nl2br("<br />");
					//close sql connections//
					$conn1->close();
					$conn2->close();
					//----------//
					header("Location: defeated.php");     //move user to defeated page
			}
			
		}
		$_SESSION["defeated"] = 0;                      //set defeated session to 0
		$_SESSION["enemynum"] = $enemy;                //set enemynum session to enemy
		header("Location: fight.php");                  //send user to fight page
	}
	
	//if the user has a key//
	else if ($row['key_id']>0){
		echo "check key_id game data";
		echo nl2br("<br />");

		$_SESSION["keynum"]=$row['key_id'];             //set ses. keynum to key id from db
		$roomkey = $row['key_id'];                      //set room key to key id
		$sql2 = "SELECT * FROM `keychain_tbl` WHERE `stage` = ".$stage." AND `user_id` = ".$id.";";     //select keys from the key chain
		$result2 = $conn2->query($sql2) or trigger_error($conn2->error."[$sql2]");                      //place keys into results

		//search through user keys
		while($row2=$result2->fetch_assoc()){
			echo "search through user data keychain";
			echo nl2br("<br />");
			$userkey=$row2['key_number'];  //set users key to key number
			echo "before key check";
	       
			//if the user has the right key, set haskey to 1
			if($userkey == $roomkey){
				$haskey=1;
			}

		}//end of search
		if($haskey == 1){
			echo "has key = 1";
			echo nl2br("<br />");
			$_SESSION["haskey"] = $haskey;   //set session haskey to haskey value
			//close sql connections//
			$conn1->close();
			$conn2->close();
			//-------//
			header("Location: findkey.php");  //send user to findkey page
		}
		//if the user doesn't have the key//
		else if($haskey==0){
			echo nl2br("<br />");
			$_SESSION["haskey"]=$haskey;     //set session haskey to haskey value
			//closing sql connections//
			$conn1->close();
			$conn2->close();
			//----------//
			header("Location: findkey.php"); //send user to findkey page
		}
	}//end check if room has key


	//Check if locked room
	else if ($lock>0){
		echo nl2br("<br />");
		$key=0;
		$sql2 = "SELECT * FROM `keychain_tbl` WHERE `stage` = ".$stage." AND `user_id` = ".$id.";";   //select keys from keychain
		$result2 = $conn2->query($sql2) or trigger_error($conn2->error."[$sql2]");                    //place keys into results
		echo nl2br("<br />");

		//search through users keys
		while($row2 = $result2->fetch_assoc()){
			echo "user key number: ".$row2['key_number'];
			echo nl2br("<br />");
			if($row2['key_number']==$lock){
				$key=$row2['key_number'];
			}
		}
		//has key
		if($key == $lock){
			echo "inside transfer to lock.php";
			echo nl2br("<br />");
			$conn1->close();
			$conn2->close();
			$_SESSION["lock"] = 1;
			echo $key;
			echo nl2br("<br />");
			header("Location: Locked.php");
		}
		//doesn't have key
		else if($key != $lock){
			echo $key;
			echo nl2br("<br />");
			echo $lock;
			echo nl2br("<br />");
			echo "inside doesnt have key else if";
			echo nl2br("<br />");
			$conn1->close();
			$conn2->close();
			$_SESSION["lock"] = 0;
			header("Location: Locked.php");
		}
		
	}//end check if room locked
	else{

		echo "end of giant while";
		echo nl2br("<br />");
		$sql2 = "UPDATE `user_tbl` SET `room` = '".$newroom."' WHERE `user_tbl`.`user_id` = ".$id.";";
		mysqli_query($conn2, $sql2);

		echo $cur_ns." ";
		echo $cur_we." ";
		echo $newroom." ";
		//close sql connections//
		$conn1->close();
		$conn2->close();
		//-----------//
		
		header("Location: run_game.php");      //send user to run game page
	}
}
?>
</BODY>
</HTML>
