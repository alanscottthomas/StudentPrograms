<!DOCTYPE>
<HTML>
	<HEAD>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
		<TITLE>Goal</TITLE>
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
	left:35%;
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
//start php session//
session_start();
//-----------//

//assign variables to session data//
$enemy = $_SESSION["enemynum"];
$id = $_SESSION["id"];
$_SESSION["id"] = $id;
$defeated = $_SESSION["defeated"];
$newroom = $_SESSION["newroom"];
$stage = $_SESSION["stage"];
$_SESSION["stage"] = $stage;
$host="localhost";
//-----------//

//assign DB connection info//
$u="root_se";
$p="Griffen644/";
$db="game";
$db2 = "game_user";
//----------//

$enemyname;
$enemytype;

//initiatiing variables//
$enemy_id=0;
$enemy_id2=0;
$user_id=0;
$stage_id=0;
$current_room = 0;
//-------//

//create connection to game DB//
$conn1 = new mysqli($host, $u, $p, $db);
if(! $conn1){
	printf("Connection failed: %s\n",$conn1->connect_error);
	exit();
}
//-----------//

//create connection to user db//
$conn2 = new mysqli($host,$u,$p,$db2);
if(! $conn2){
	prinf("Connection failed: %s\n",$conn2->connect_error);
	exit();
}
//---------//


//get health info//
$sql3 = "SELECT * FROM `user_tbl` WHERE `user_id` = ".$id.";";              //select user data from table
$result3 = $conn2->query($sql3) or trigger_error($conn2->error."[$sql3]");  //place data into results

//place user data into rows//
while($row1 = $result3->fetch_assoc()){
	$health = $row1['health'];
	$sword = $row1['sword'];
	$shield = $row1['shield'];
}
//---------//



//get enemy info//
$sql1 = "SELECT * FROM `enemy_tbl` WHERE `enemy_id` = ".$enemy.";";        //pull enemy info
$result1 = $conn1->query($sql1) or trigger_error($conn1->error."[$sql1]"); //place enemy data into results
//place user data into rows//
while($row1 = $result1->fetch_assoc()){
	$enemy_id2 = $row1['enemy_id'];
	$enemyname = $row1['name'];
	$enemytype = $row1['difficulty'];
}
//---------//



//priting notification that the goal has been found//
echo "<enemy_info>";
$damage = rand(10,30);
$current_health = $health;
echo "You've found the treasure and beat the level!";
echo "</enemy_info>";
//--------------//
	
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



//health images//
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



$sql2 = "UPDATE `user_tbl` SET `room` = '".$newroom."' WHERE `user_tbl`.`user_id` = ".$id.";";           //update current room for user
mysqli_query($conn2, $sql2);  //execute SQL statement
	
$sql4 = "UPDATE `user_tbl` SET `health` = '".$current_health."' WHERE `user_tbl`.`user_id` = ".$id.";"; //update user's health
mysqli_query($conn2, $sql4);  //execute SQL statement
		
echo nl2br("<br>");
echo nl2br("<br>");
	
echo "<img src='chest.png' height='400' width='1017'>";    //display the chest image
	
	
	
	
	
	//player is dead//
	if($current_health > 0)
		{
		echo "<a class='button' href='run_game.php' style='vertical-align:middle'>
		<span>restart </span>
		</button>";
		
		//move player to first room of the level//
		$sql5 = "UPDATE user_tbl set room = 1 , sword = 0, shield = 0, stage =  " . $stage .  " WHERE user_id = " . $id;     //reset user to default stats
		if ($conn2->query($sql5) === TRUE) {
			} 
				else {
						echo "Error updating record: " . $conn2->error;
					}
		
		//change player health to 100//
		$sql6 = "UPDATE user_tbl set health = 100 WHERE user_id = " . $id;
		if ($conn2->query($sql6) === TRUE) {
			//echo "Health has been restored";
			} 
				else {
						echo "Error updating record: " . $conn2->error;
					}
		
		//delete from keychain
		$sql = "delete from keychain_tbl where user_id = " .$id;
		if ($conn2->query($sql) === TRUE) {
    
		} 
		else {
			echo "Error updating record: " . $conn2->error;
		}
		//delete defeated where user id = id
		$sql = "delete from defeated_tbl where user_id = " .$id; 
		if ($conn2->query($sql) === TRUE) {
		//echo "Your level has been changed";
		} 
		else {
			echo "Error updating record: " . $conn2->error;
		}
	}
	//---------------------//
?>
<!--get key press-->
<script>
$(document).keypress(function(e) {
	if (e.which == 32) {
		location.href = "run_game.php";
	}
});
</script>
<!---------->

	
<?php	
//close sql connections//
$conn1->close();
$conn2->close();
//--------//
?>
	</body>
</HTML>



