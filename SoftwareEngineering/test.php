<!DOCTYPE>
<HTML>
<HEAD>
<STYLE>
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

    .move {
  position: absolute;
  top: 26%;
  left: 20%;
  margin: -150px 0 0 -150px;
  width:300px;
  height:300px;
}

.move a {
	color: black; text-shadow: 0 0 10px rgba(255,0,0,100); letter-spacing:1px; text-align:center; 

}
</STYLE>
</HEAD>
<BODY>

<?php
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";

$conn = new mysqli($host, $u, $p, $db);
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}

$sql = "select * from room_map_tbl where stage_id = 1;";

echo "<table border='1' cellpadding='0' cellspacing='0' style='border-collapse: collapse' height = '600' width='1000'>";

$cur_room = 0;
echo "<br>";
for($i=4;$i>-5;$i--){
	echo "<tr>";
	for($j=-4;$j<5;$j++){
		$color = "black";
		$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
		while ($row = $result->fetch_assoc()){
			if($i==$row['ns']&&$j==$row['we']){
				$color = $row['color'];
				//$cur_room = $row['room_number'];
			}
		}
		echo "<td height='11%' width='11%' bgcolor='".$color."'>";
		echo "<form action = 'room.php' method = 'post'>";
		echo "<button name='spot' type='submit' value='".$j.",".$i.",1'>".$j.",".$i."</button>";
		echo "</form>";
		echo"</td>";
		$cur_room = 0;
	}
	echo "</tr>";
}
//$_SESSION["stage"]=$stage;

$conn->close();
?>
</table>
</BODY>
</HTML>