<!DOCTYPE>
<HTML>
<HEAD>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<TITLE>FIGHT!!</TITLE>
<STYLE>
a {
    color: #fbb03b;
	background-color: black;
	position: absolute;
	top:90%;
	left:77%;
	z-index: 2;
	border: 1px solid #fbb03b;
    border-radius: 0px;
	
}




body {
	background-color:black;
	color: white;	
}

enemy_info{
	position: absolute;
	top:75.5%;
	left:25%;
	padding: 2px;
	z-index:1;
	background-color: black;
	color: #fbb03b;
	border: 1px solid #fbb03b;
    border-radius: 0px;
	
}


table{
	position: absolute;
	top:0%;
	left:90.125%;
	border-color:#fbb03b;
}


img {
    position: absolute;
	top:0%;
	left:0%;
	border: 1px solid #fbb03b;
    border-radius: 0px;
    padding: 0px;
}


.health_div * {
    position: absolute;
	top:350%;
	left:-1300%;
    padding: 0px;
	border: 0px solid #FFFFFF;
    border-radius: 0px;
}


.sword_div * {
    position: absolute;
	top:350%;
	left:700%;
    padding: 0px;
	border: 0px solid #FFFFFF;
    border-radius: 0px;
}


.shield_div * {
    position: absolute;
	top:350%;
	left:1200%;
    padding: 0px;
	border: 0px solid #FFFFFF;
    border-radius: 0px;
}



health_text{
	position: absolute;
	top:80.25%;
	left:14%;
    padding: 2px;
	z-index:1;
	background-color: black;
	color: #fbb03b;
	border: 1px solid #fbb03b;
    border-radius: 0px;
}



inventory_text{
	position: absolute;
	top:80.25%;
	left:45%;
    padding: 2px;
	z-index:1;
	background-color: black;
	color: #fbb03b;
	border: 1px solid #fbb03b;
    border-radius: 0px;
}




options_text{
	position: absolute;
	top:80.25%;
	left:82%;
    padding: 2px;
	z-index:1;
	background-color: black;
	color: #fbb03b;
	border: 1px solid #fbb03b;
    border-radius: 0px;
}




div {
    position: absolute;
	top:70%;
	left:25%;
    padding: 10px;  
}



change_level_div {
    position: absolute;
	top:80%;
	left:75%;
    padding: 10px;
}








map_div {
    position: absolute;
	top:20%;
	left:93.5%;
    padding: 2px;
	z-index:1;
	background-color: black;
	color: #fbb03b;
	border: 1px solid #fbb03b;
    border-radius: 0px;
}






.button {
  position: absolute;
	top:87%;
	left:79.5%;
	z-index: 1;
  display: inline-block;
  border-radius: 4px;
  background-color: #fbb03b;
  border: none;
  color: #000000;
  text-align: center;
  font-size: 20px;
  padding: 5px;
  width: 100px;
  transition: all 0.5s;
  cursor: pointer;
  margin: 5px;
}

.button span {
  cursor: pointer;
  display: inline-block;
  position: relative;
  transition: 0.5s;
}

.button span:after {
  content: '\00bb';
  position: absolute;
  opacity: 0;
  top: 0;
  right: -20px;
  transition: 0.5s;
}

.button:hover span {
  padding-right: 25px;
}

.button:hover span:after {
  opacity: 1;
  right: 0;
}









</STYLE>
</HEAD>
<BODY>
	
<?php
//starting PHP session//
session_start();
//----------//

//setting variables to the data passed from the session//
$enemy = $_SESSION["enemynum"];
$id = $_SESSION["id"];
$_SESSION["id"] = $id;
$defeated = $_SESSION["defeated"];
$newroom = $_SESSION["newroom"];
$stage = $_SESSION["stage"];
$_SESSION["stage"] = $stage;
$host="localhost";
//-------------//

//setting DB connection info//
$u="root_se";
$p="Griffen644/";
$db="game";
$db2 = "game_user";
//------------//

$enemyname;
$enemytype;

//initializing variables//
$enemy_id=0;
$enemy_id2=0;
$user_id=0;
$stage_id=0;
$current_room = 0;
$is_defeated = false;
//-----------------//

//try to connect to the game DB//
$conn1 = new mysqli($host, $u, $p, $db);
if(! $conn1){
	printf("Connection failed: %s\n",$conn1->connect_error);
	exit();
}
//--------------//

//try to connect to the user DB//
$conn2 = new mysqli($host,$u,$p,$db2);
if(! $conn2){
	prinf("Connection failed: %s\n",$conn2->connect_error);
	exit();
}
//--------------//

//get health info//
$sql3 = "SELECT * FROM `user_tbl` WHERE `user_id` = ".$id.";";               //select user info
$result3 = $conn2->query($sql3) or trigger_error($conn2->error."[$sql3]");   //save user info to results
//--------//

//placing user data into rows//
while($row1 = $result3->fetch_assoc()){   
	$health = $row1['health'];
	$sword = $row1['sword'];
	$shield = $row1['shield'];
}
//---------//



//get enemy info//
$sql1 = "SELECT * FROM `enemy_tbl` WHERE `enemy_id` = ".$enemy.";";        //pulling enemy data
$result1 = $conn1->query($sql1) or trigger_error($conn1->error."[$sql1]");  //saving enemy data to rows
//-------------//

//placing enemy data into rows//
while($row1 = $result1->fetch_assoc()){
	$enemy_id2 = $row1['enemy_id'];
	$enemyname = $row1['name'];
	$enemytype = $row1['difficulty'];
}
//---------//


//get defeated info//
$sql2 = "SELECT * FROM `defeated_tbl` WHERE `user_id` = ".$id.";";            //pull data from defeated table
$result2 = $conn2->query($sql2) or trigger_error($conn2->error."[$sql2]");    //saving the results
//----------//

//placing defeated info into rows//
while($row1 = $result2->fetch_assoc()){
	$enemy_id = $row1['enemy_id'];
	$user_id = $row1['user_id'];
	$stage_id = $row1['stage'];
	$current_room = $row1['room'];
//---------//
	
	//if the enemy has been defeated for the current room set is_defeated to true
	if($enemy_id2 == $enemy_id && $user_id == $id && $stage_id == $stage && $newroom == $current_room)
	{
	$is_defeated = true;	
	}
}

//if the enemy has already been defeated continue playing the game
if ($is_defeated == true)
{
		$current_health = $health;
		$sql4 = "UPDATE user_tbl SET health = '$current_health' WHERE user_tbl.user_id = '$id';";  //update user health
		mysqli_query($conn2, $sql4);                //execute SQL query
		header('Location: run_game.php');           //send user to run game page
}
//-------------------//

	$sql2 ="INSERT INTO defeated_tbl (enemy_id, user_id, stage, room) VALUES ('$enemy', '$id', '$stage', '$newroom');"; //place enemy data into the defeated table
	mysqli_query($conn2, $sql2);       //execute update command

	
	echo "<enemy_info>";      //calling CSS
	$damage = rand(10,30);    //generating damage received from the enemy
	
	
	//shield and sword negate//
	if($shield > 0 && $sword > 0)
	{
		$damage = $damage / 2;       //if the user has a shield and shield divide the damage by 2
		$rounded = round($damage,2);
		$damage = $rounded;
	}
	//------------//
	
	//shield negate//
	if($shield > 0 && $sword == 0)
	{
		$damage = $damage / 1.2;        //if the player has a shield reduce dmg by 20%
		$rounded = round($damage,2);
		$damage = $rounded;
	}
	//--------------------//
	
	//sword negate
	if($shield == 0 && $sword > 0)
	{
		$damage = $damage / 1.2;       //if the player has a sword reduce dmg by 20%
		$rounded = round($damage,2);
		$damage = $rounded;
	}
	//---------------//
	
	$current_health = $health-$damage;    //setting user's health to health minus the dmg received
	
	
	//if the player survived display this msg
	if ($current_health > 0)
	{
		echo $enemyname." hit you for ".$damage." health points before you were able to slay the beast!";
	}
	//------------------//
	
	//if the player did not survive display this msg//
	if ($current_health <= 0)
	{
		echo "You lay bruised and beaten after " .$enemyname." hit you for ".$damage." health points. May your good deeds live on.";
	}
	//-----------//
	echo "</enemy_info>";      //closing CSS

	
	//OPTIONS//
//text above options//
echo "<options_text>";
echo"options";
echo "</options_text>";
//------//	
	
	
	
	//HEALTH//
//text above hearts//
echo "<health_text>";
echo"health";
echo "</health_text>";
//------//


//inventory//
//text above hearts//
echo "<inventory_text>";
echo"inventory";
echo "</inventory_text>";
//------//



//inventory pics//
//has sword//
if($sword > 0 )
{
	echo "<div class ='sword_div'>";
	echo "<img src='sword_on.png'>";
	echo "</div>";
}
//----------------//


//has sword//
if($shield > 0 )
{
	echo "<div class ='shield_div'>";
	echo "<img src='shield_on.png'>";
	echo "</div>";
}
//----------------//

//health pics//
//5 hearts//
if($current_health >= 80)
{
	echo "<div class ='health_div'>";
	echo "<img src='5_hearts.png'>";
	echo "</div>";
}
//----------------//

//4 hearts//
if($current_health >=  60 && $current_health <  80 )
{
	echo "<div class ='health_div'>";
	echo "<img src='4_hearts.png'>";
	echo "</div>";
}
//----------------//


//3 hearts//
if($current_health >=  40 && $current_health <  60 )
{
	echo "<div class ='health_div'>";
	echo "<img src='3_hearts.png'>";
	echo "</div>";
}
//----------------//


//2 hearts//
if($current_health >=  20 && $current_health <  40 )
{
	echo "<div class ='health_div'>";
	echo "<img src='2_hearts.png'>";
	echo "</div>";
}
//----------------//


//1 hearts//
if($current_health >=  1 && $current_health <  20 )
{
	echo "<div class ='health_div'>";
	echo "<img src='1_hearts.png'>";
	echo "</div>";
}
//----------------//


//0 hearts//
if($current_health <= 0 )
{
	echo "<div class ='health_div'>";
	echo "<img src='0_hearts.png'>";
	echo "</div>";
}
//----------------//


 	$sql2 = "UPDATE `user_tbl` SET `room` = '".$newroom."' WHERE `user_tbl`.`user_id` = ".$id.";";  //updating user's current room
	mysqli_query($conn2, $sql2);   //execute SQL statement
	
	//if the enemy has not been defeated calculate new health//
	if($is_defeated == false)
	{
	$sql4 = "UPDATE `user_tbl` SET `health` = '".$current_health."' WHERE `user_tbl`.`user_id` = ".$id.";";  //update user's health with dmg calc
	mysqli_query($conn2, $sql4);    //execute SQL statement
	}
	//---------------//
	
	//if the enemy has been defeated before//
	if($is_defeated == true)
	{
	$sql4 = "UPDATE `user_tbl` SET `health` = '".$health."' WHERE `user_tbl`.`user_id` = ".$id.";";   //set health to health before dmg
	mysqli_query($conn2, $sql4);         //execute SQL statement
	}
	
	echo nl2br("<br>");
	echo nl2br("<br>");
	
	
//if statements for enemy image//
	//elf
	if($enemyname == "Elf")
{
	echo "<img src='elf.png' height='400' width='1017'>";
}
	//skeleton
	if($enemyname == "Skeleton")
{
	echo "<img src='skeleton.png' height='400' width='1017'>";
}

	//spider
	if($enemyname == "Spider")
{
	echo "<img src='spider.png' height='400' width='1017'>";
}


//witch
	if($enemyname == "Witch")
{
	echo "<img src='witch.png' height='400' width='1017'>";
}
	
$alive=0;
//if statements for checking if user is alive//
	//player survived
	if($current_health > 0)
		{
		$alive=1;	
		echo "<a class='button' id='continue' href='run_game.php' style='vertical-align:middle'><span>continue </span></button>";
		}
		
	//player is dead//
	if($current_health <= 0)
		{
		$alive=0;
		echo "<a class='button' id='continue1' href='run_game.php' style='vertical-align:middle'><span>restart </span></button>";
		$sql5 = "UPDATE user_tbl set room = 1 , sword = 0, shield = 0, stage =  " . $stage .  " WHERE user_id = " . $id;  //set player info to defaults
		
		//try to execute SQL statement//
		if ($conn2->query($sql5) === TRUE) {
			} 
				else {
						echo "Error updating record: " . $conn2->error;
					}
		
		//change player health to 100//
		$sql6 = "UPDATE user_tbl set health = 100 WHERE user_id = " . $id;   //reset player health
		if ($conn2->query($sql6) === TRUE) {
			//echo "Health has been restored";
			} 
				else {
						echo "Error updating record: " . $conn2->error;
					}
		
		
		//delete from keychain
$sql = "delete from keychain_tbl where user_id = '$id';";     //remove any keys
if ($conn2->query($sql) === TRUE) {
} else {
    echo "Error updating record: " . $conn2->error;
}
//------//

//delete defeated where user id = id
$sql = "delete from defeated_tbl where user_id = '$id';"; 
if ($conn2->query($sql) === TRUE) {
    //echo "Your level has been changed";
} 
else {
    echo "Error updating record: " . $conn2->error;
		
		}
	//---------------------//
		}
?>
<!--get key press-->
<script>
$(document).keypress(function(e) {
	<!--setting Jscript values to php values-->
	var alive = <?php echo $alive; ?>;
	
	<!-------------------------------------->
	
	if (e.which == 32 && alive == 1) {
		location.href = "run_game.php";
	}
	
	if (e.which == 32 && alive == 0) {
		location.href = "run_game.php";
	}
	
});
</script>
<!---------->		
<?php		
//close SQL connections//		
$conn1->close();
$conn2->close();
//------------//
?>



</body>
</HTML>