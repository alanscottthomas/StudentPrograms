<!DOCTYPE>
<HTML>
<HEAD>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<TITLE>Found A Key!</TITLE>
<body style="background-color:black;">
		<font color="white">
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
	left:45%;
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
//---------//

//set variables to data from sessions//
$haskey = $_SESSION["haskey"];
$keynum = $_SESSION["keynum"];
//-----------//

//set DB connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db2 = "game_user";
//-------------//

//set variables from sessions//
$newroom = $_SESSION["newroom"];
$id = $_SESSION["id"];
$stage = $_SESSION["stage"];
//-------------//

//try to connect to the DB//
$conn2 = new mysqli($host,$u,$p,$db2);
if(! $conn2){
	prinf("Connection failed: %s\n",$conn2->connect_error);
	exit();
}
//-----------//

//get health info//
$sql3 = "SELECT * FROM `user_tbl` WHERE `user_id` = ".$id.";";                //select user info
$result3 = $conn2->query($sql3) or trigger_error($conn2->error."[$sql3]");    //save data to results
//place user data into rows//
while($row1 = $result3->fetch_assoc()){
	$health = $row1['health'];
	$sword = $row1['sword'];
	$shield = $row1['shield'];
}
//---------//

$current_health = $health;    //set current health

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







//if the user doesn't have the key//
if($haskey==0){
	echo "<enemy_info>";
		echo "You found a key!";
	echo "</enemy_info>";

	$sql2 = "INSERT INTO `keychain_tbl` (`id`, `key_number`, `stage`, `user_id`) VALUES (NULL, '".$keynum."', '".$stage."', '".$id."');"; //insert key data into keychain
	mysqli_query($conn2, $sql2);

	$sql2 = "UPDATE `user_tbl` SET `room` = '".$newroom."' WHERE `user_tbl`.`user_id` = ".$id.";";  //update user's room
	mysqli_query($conn2, $sql2);
	
	$sql2 = "UPDATE `user_tbl` SET `health` = '".$health."' WHERE `user_tbl`.`user_id` = ".$id.";";  //update user's health
	mysqli_query($conn2, $sql2);
	
	echo "<img src='key.png' height='400' width='1017'>";

	echo "<a class='button' href='run_game.php' style='vertical-align:middle'><span>continue </span></button>";
}
//--------------//


//if the user already has the key//
else if($haskey==1){
	$sql2 = "UPDATE `user_tbl` SET `room` = '".$newroom."' WHERE `user_tbl`.`user_id` = ".$id.";";  //set user's room
	mysqli_query($conn2, $sql2);    //execute SQL statement
	$sql2 = "UPDATE `user_tbl` SET `health` = '".$health."' WHERE `user_tbl`.`user_id` = ".$id.";";  //update user's health
	mysqli_query($conn2, $sql2);      //execute SQL statement
	header("Location: run_game.php");  //send user back to run game page
}
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
$conn2->close();
?>
</BODY>
</HTML>