<!DOCTYPE>
<HTML>
<HEAD><TITLE>Current stages</TITLE></HEAD>
<BODY>
	<body style="background-color:black;">
		<font color="white">
<style>
h1{
	color:white;
	
}
</style>
<h1>please select a stage</h1>

<?php
//set db connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
$counter=0;
//-----------//

//try to connect to db//
$conn = new mysqli($host, $u, $p, $db);
if(! $conn){
	printf("Connection failed: %s\n",$conn->connect_error);
	exit();
}
//-----------//

//populate dropdown menu with available stages//
echo "<form action = 'stage_creation_2.php' method = 'post'>";
echo "<select name = 'stage'>";
echo "<option value = '0'>No Stage</option>";
$sql = "select * from stage_tbl";
$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
while($row=$result->fetch_assoc()){
	$counter++;
	echo "<option value = ".$row['stage_id'].">".$row['stage_id']."</option>";
}
//----------------//

$conn->close();        //close the connection to the DB
?>
</select>
<input type = 'submit'>
</form>
</BODY>
</HTML>