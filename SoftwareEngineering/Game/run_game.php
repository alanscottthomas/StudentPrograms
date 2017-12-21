<!DOCTYPE>
<HTML>
<HEAD>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

<TITLE>"Run game"</TITLE>
<STYLE>

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
	top:81%;
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


north_button {
    position: absolute;
	top:-7%;
	left:45%;
    padding: 10px;
}


south_button {
    position: absolute;
	top:58%;
	left:45%;
    padding: 10px;
}


west_button {
    position: absolute;
	top:32%;
	left:0%;
    padding: 10px;
}


east_button {
    position: absolute;
	top:32%;
	left:88%;
    padding: 10px;
}

</STYLE>
<BODY>
<body style="background-color:black;">
<font color="white">
			
		
<?php
//start php session//
session_start();
//---------//

//initialize variables//
$judge = 0;
$jns = -11;
$jwe = -11;
//---------//

//set variables to session values//
$id = $_SESSION["id"];
$user = $_SESSION["user"];
//---------//

//set db connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
$db2 = "game_user";
//------//


$conn = new mysqli($host, $u, $p, $db);   //connect to game db

$conn2 = new mysqli($host,$u,$p,$db2);   //connect to user db

//if cant connect to user db//
if(! $conn2){
	prinf("Connection failed: %s\n",$conn2->connect_error);
	exit();
}
//------//

//initialize variables//
$room=0;
$stage=0;
$current_health=0;
//-----------//

$sql_user = "SELECT * FROM `user_tbl` WHERE `user_id` = ".$id.";";                  //select user data
$result2 = $conn2->query($sql_user) or trigger_error($conn2->error."[$sql_user]");  //save user data to results

//place user data into rows//
while ($row2 = $result2->fetch_assoc()){
	$room = $row2['room'];
	$stage = $row2['stage'];
	$current_health = $row2['health'];
	$sword = $row2['sword'];
	$shield = $row2['shield'];
}
//--------------//

//set session values to room and stage data//
$_SESSION["room"] = $room;
$_SESSION["stage"] = $stage;
//--------//


$sql ="SELECT * FROM `room_map_tbl` WHERE `stage_id` = ".$stage.";";          //select room data from the db
echo "<table border='1' cellpadding='0' cellspacing='0' style='border-collapse: collapse' height = '100' width='100'>";
$cur_room = 0;

//for looop to build the table for the mini map//
for($i=4;$i>-5;$i--){
	echo "<tr>";
	for($j=-4;$j<5;$j++){
		$color = "black";
		$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
		while ($row = $result->fetch_assoc()){
			if($i==$row['ns']&&$j==$row['we']){
				$color = "white";
				if($row['room_number']==$room){
					$color = "blue";
					$judge = $row['room_number'];
					$jns = $row['ns'];
					$jwe = $row['we'];
				}
			}
		}
		echo "<td height='11%' width='11%' bgcolor='".$color."'>";
		
		echo"</td>";
		$cur_room = 0;
	}
	echo "</tr>";
}
//------------------//

//set variables to direction values//
$north = 1 + $jns;
$south = -1 + $jns;
$west = -1 + $jwe;
$east = 1 + $jwe;
$ncheck = 0;
$scheck = 0;
$wcheck = 0;
$echeck = 0;
//----------//


//select statements to determine if the user can go south,north,west,east//
$sql = "SELECT * FROM `room_map_tbl` WHERE `stage_id` = ".$stage." AND `ns` = ".$north." AND `we` = ".$jwe.";";  //select direction info from room map table
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");                                            //place direction info into results              
while ($row = $result->fetch_assoc()){
	if($row['room_number']>0){
		$ncheck = 1;
	}
}

$sql = "SELECT * FROM `room_map_tbl` WHERE `stage_id` = ".$stage." AND `ns` = ".$south." AND `we` = ".$jwe.";";   //select direction info from room map table
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");                                             //place direction info into results
while ($row = $result->fetch_assoc()){
	if($row['room_number']>0){
		$scheck = 1;
	}
}

$sql = "SELECT * FROM `room_map_tbl` WHERE `stage_id` = ".$stage." AND `ns` = ".$jns." AND `we` = ".$west.";";   //select direction info from room map table
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");                                            //place direction info into results
while ($row = $result->fetch_assoc()){
	if($row['room_number']>0){
		$wcheck = 1;
	}
}

$sql = "SELECT * FROM `room_map_tbl` WHERE `stage_id` = ".$stage." AND `ns` = ".$jns." AND `we` = ".$east.";";   //select direction info from room map table
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");                                           //place direction info into results
while ($row = $result->fetch_assoc()){
	if($row['room_number']>0){
		$echeck = 1;
	}
}
//---------------//


echo "<map_div>map</map_div>";

//--CODE TO DISPLAY CORRIDOORS--//

//north options//
//can only go north
if($ncheck == 1 && $wcheck == 0 && $echeck == 0)
{
	echo "<img src='n.png' height='400' width='1017'>";
}
//

//can go n , w , e
if($ncheck == 1 && $wcheck == 1 && $echeck == 1)
{
	echo "<img src='n_w_e.png' height='400' width='1017'>";
}
//

//can go n , w 
if($ncheck == 1 && $wcheck == 1 && $echeck == 0)
{
	echo "<img src='n_w.png' height='400' width='1017'>";
}
//

//can go n , e 
if($ncheck == 1 && $wcheck == 0 && $echeck == 1)
{
	echo "<img src='n_e.png' height='400' width='1017'>";
}
//


//west opttions//
//can go only west
if($ncheck == 0 && $wcheck == 1 && $echeck == 0)
{
	echo "<img src='w.png' height='400' width='1017'>";
}
//


//can go w,e
if($ncheck == 0 && $wcheck == 1 && $echeck == 1)
{
	echo "<img src='w_e.png' height='400' width='1017'>";
}
//


//east options//
//can go only east
if($ncheck == 0 && $wcheck == 0 && $echeck == 1)
{
	echo "<img src='e.png' height='400' width='1017'>";
}
//


//south options//
//can go only south
if($ncheck == 0 && $wcheck == 0 && $echeck == 0 && $scheck == 1)
{
	echo "<img src='s.png' height='400' width='1017'>";
}
//



//MOVE NORTH FORM//
echo  "<north_button>";
echo "<form action = 'moving.php' id='north_form' method = 'post'>";

if($ncheck == 1){
echo "<input type='hidden' name='dir' value='north'>";
echo  "<input type='image' value='dir' src='north_arrow.png'>";
}
echo "</form>";
echo  "</north_button>";
//-----------------//


//MOVE SOUTH FORM//
echo "<south_button>";
echo "<form action = 'moving.php' id='south_form' method = 'post'>";

if($scheck == 1){
echo "<input type='hidden' name='dir' value='south'>";
echo  "<input type='image' value='south' src='south_arrow.png'>";
}

echo "</form>";
echo  "</south_button>";
//--------------//


//MOVE WEST FORM//
echo "<west_button>";
echo "<form action = 'moving.php' id='west_form' method = 'post'>";

if($wcheck == 1){
echo "<input type='hidden' name='dir' value='west'>";
echo  "<input type='image' value='west' src='west_arrow.png'>";
}

echo "</form>";
echo  "</west_button>";
//--------------//

//MOVE EAST FORM//
echo "<east_button>";
echo "<form action = 'moving.php' id='east_form' method = 'post'>";

if($echeck == 1){
echo "<input type='hidden' name='dir' value='east'>";
echo  "<input type='image' value='east' src='east_arrow.png'>";
}

echo "</form>";
echo  "</east_button>";
//--------------//
?>

<!--keypress movement -->
<script>
$(document).keypress(function(e) {
	<!--setting Jscript values to php values-->
	var ncheck = <?php echo $ncheck; ?>;
	var scheck = <?php echo $scheck; ?>;
	var wcheck = <?php echo $wcheck; ?>;
	var echeck = <?php echo $echeck; ?>;
	<!-------------------------------------->
	
	if (e.which == 87 && ncheck == 1 || e.which == 119 && ncheck == 1) {
		$("#north_form").submit();
	}
	
	if (e.which == 115 && scheck == 1 || e.which == 83 && scheck == 1) {
		$("#south_form").submit();
	}
	
	if (e.which == 65 && wcheck == 1 || e.which == 97 && wcheck == 1) {
		$("#west_form").submit();
	}
	
	if (e.which == 68 && echeck == 1 || e.which == 100 && echeck == 1) {
		$("#east_form").submit();
	}
});
</script>
<!--end keypress movement -->


<?php
//close sql connections//
$conn->close();
$conn2->close();
//----------//
?>

</BODY>
</HTML>



<!DOCTYPE>
<HTML>
<HEAD><TITLE>Current stages</TITLE></HEAD>
<BODY>
<style>
h1{
	color:blue;
}
</style>


<?php

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




	//OPTIONS//
//text above options//
echo "<options_text>";
echo"options";
echo "</options_text>";
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


//has shield//
if($shield > 0 )
{
	echo "<div class ='shield_div'>";
	echo "<img src='shield_on.png'>";
	echo "</div>";
}
//----------------//

//heart pics//
//5 hearts//
if($current_health >= 80)
{
	echo "<div class ='health_div'>";
	echo "<img src='5_hearts.png'>";
	//echo "Health: " . $_SESSION["health"] . "<br>";
	echo "</div>";
}
//----------------//

//4 hearts//
if($current_health >=  60 && $current_health <  80 )
{
	echo "<div class ='health_div'>";
	echo "<img src='4_hearts.png'>";
	//echo "Health: " . $_SESSION["health"] . "<br>";
	echo "</div>";
}
//----------------//


//3 hearts//
if($current_health >=  40 && $current_health <  60 )
{
	echo "<div class ='health_div'>";
	echo "<img src='3_hearts.png'>";
	//echo "Health: " . $_SESSION["health"] . "<br>";
	echo "</div>";
}
//----------------//


//2 hearts//
if($current_health >=  20 && $current_health <  40 )
{
	echo "<div class ='health_div'>";
	echo "<img src='2_hearts.png'>";
	//echo "Health: " . $_SESSION["health"] . "<br>";
	echo "</div>";
}
//----------------//


//1 hearts//
if($current_health >=  1 && $current_health <  20 )
{
	echo "<div class ='health_div'>";
	echo "<img src='1_hearts.png'>";
	//echo "Health: " . $_SESSION["health"] . "<br>";
	echo "</div>";
}
//----------------//


//0 hearts//
if($current_health <= 0 )
{
	echo "<div class ='health_div'>";
	echo "<img src='0_hearts.png'>";
	//echo "Health: " . $_SESSION["health"] . "<br>";
	echo "</div>";
}
//----------------//




//change level//
echo  "<change_level_div>";
echo "<p>change the level you are on</p>";


$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
$counter=0;

$conn = new mysqli($host, $u, $p, $db);
if(! $conn){
	printf("Connection failed: %s\n",$conn->connect_error);
	exit();
}

$_SESSION['user']=$id;

echo "<form action = 'change_level.php' method = 'post'>";
echo "<select name = 'stage'>";
echo "<option value = '0'>No Stage</option>";
$sql = "select * from stage_tbl";
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
while($row=$result->fetch_assoc()){
	$counter++;
	echo "<option value = ".$row['stage_id'].">".$row['stage_id']."</option>";
}

echo  "</change_level_div>";
$conn->close();
//-------------------------------------//
?>

</select>
<input type = 'submit'>
</form>
	</font>
		</div>
		</BODY>
</HTML>