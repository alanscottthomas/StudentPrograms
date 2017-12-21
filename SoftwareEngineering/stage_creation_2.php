<?php
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
?>

</!DOCTYPE>
<HTML>
<BODY>
<style>

.move a {
	color: #FBB03B; text-shadow: 0 0 0px rgba(255,0,0,100); letter-spacing:1px; 

}

    .button {
        text-align: center;
        margin:auto;
        vertical-align: middle;
        padding:0px 0px;
        width:20px;
        height:20px;
        display:block;
        background-color: white;
		color: red;
		border-color: red;
    }
	
	.button_black {
        
        background-color: grey;
		color: rgba(0,0,0,0);
		
		
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
    }
	
	.button_purple {
        
        background-color: purple;
		color: rgba(0,0,0,0);
		
		
		border-color: rgba(0,0,0,0);
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
    }
	
	.button_orange {
        
        background-color: orange;
		color: rgba(0,0,0,0);
		
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
    }
	
	.button_pink {
        
        background-color: pink;
		color: rgba(0,0,0,0);
		
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
    }
	
	
	.button_red {
        
        background-color: red;
		color: rgba(0,0,0,0);
		
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
    }
	
	
	.button_green {
        
        background-color: green;
		color: rgba(0,0,0,0);
		
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
    }
	
	
	.button_yellow {
        
        background-color: yellow;
		color: rgba(0,0,0,0);
		
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
		
    }
	
	
	.button_blue {
        
        background-color: blue;
		color: rgba(0,0,0,0);
		
		border-color: rgba(0,0,0,0);
		border: 0px solid;
		border-radius: 0px;
		padding: 0px;
		width:50px;
        height:50px;
    }
	
	
	
	table, th, td{
	white-space:nowrap;
	width: 5%;
	height: 0%;
	border-spacing: 0;
	border-collapse: collapse;
	border: 1px solid;
	padding: 0px;
	border-radius:1px;
	cellspacing=0;
	
	
	}
	
	table{
	position: absolute;
	top:8%;
	left:28%;
	z-index: 2;
	
	

	}
	
	form{
	margin-bottom:0em;
	display: block;
	margin-top:0em;
	}
	
	map_text{
	font-size: 20;
	position: absolute;
	top:0%;
	left:43%;
    padding: 2px;
	z-index:1;
	background-color: black;
	color: #fbb03b;
	border: 1px solid #fbb03b;
    border-radius: 0px;
}


options_text{
	font-size: 20;
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


	
	
	key_text{
	font-size: 20;
	position: absolute;
	top:12.5%;
	left:9%;
    padding: 2px;
	z-index:1;
	background-color: black;
	color: #fbb03b;
	border: 1px solid #fbb03b;
    border-radius: 0px;
}


	
	
	img {
	position: absolute;
	top:16%;
	left:1%;
	z-index: 3;
	}
	
	

	
	
	
	.button_options {
  position: absolute;
	top:87%;
	left:79.5%;
	z-index: 4;
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

.button_options span {
  cursor: pointer;
  display: inline-block;
  position: relative;
  transition: 0.5s;
}

.button_options span:after {
  content: '\00bb';
  position: absolute;
  opacity: 0;
  top: 0;
  right: -20px;
  transition: 0.5s;
}

.button_options:hover span {
  padding-right: 25px;
}

.button_options:hover span:after {
  opacity: 1;
  right: 0;
}





</style>
<br/>
<?php
//setting DB connection info//
$host="localhost";
$u="root_se";
$p="Griffen644/";
$db="game";
//--------------//

//connect to DB//
$conn = new mysqli($host, $u, $p, $db);
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}
//--------------//

	$sql = "select * from room_map_tbl where stage_id = '$stage';";           //select from room map tbl
	$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");     //put the data into results

?>
<?php 

//code to generate the table for user's to edit//
echo "<table>";
$cur_room = 0;
for($i=4;$i>-5;$i--){
	echo "<tr>";
	for($j=-4;$j<5;$j++){
		$color = "black";
		$result = $conn->query($sql) or trigger_error($conn->error."[$sql]");
		while ($row = $result->fetch_assoc()){
			if($i==$row['ns']&&$j==$row['we']){
				$color = $row['color'];
				$cur_room = $row['room_number'];
			}
		}
		echo "<td>";
		echo "<form action = 'room.php' method = 'post'>";
		//black = room doesn't exist
		if($color == 'black')
		{
			echo '<button_black>';
			echo "<button class='button_black' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		// purple = goal
		elseif($color == 'purple')
		{
			echo '<button_purple>';
			echo "<button class='button_purple' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		// sword = orange
		elseif($color == 'orange')
		{
			echo '<button_orange>';
			echo "<button class='button_orange' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		// shield = pink
		elseif($color == 'pink')
		{
			echo '<button_pink>';
			echo "<button class='button_pink' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		// monster = red
		elseif($color == 'red')
		{
			echo '<button_red>';
			echo "<button class='button_red' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		// lock = green
		elseif($color == 'green')
		{
			echo '<button_green>';
			echo "<button class='button_green' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		// key = pink
		elseif($color == 'yellow')
		{
			echo '<button_yellow>';
			echo "<button class='button_yellow' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		// empty room = blue
		elseif($color == 'blue')
		{
			echo '<button_blue>';
			echo "<button class='button_blue' name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
			echo '</div>';
		}
		
		else 
		{
			echo "<button name='spot' type='submit' value='".$j.",".$i.",".$stage."'>".$j.",".$i."</button>";
		}
		echo "</form>";
		echo"</td>";
		$cur_room = 0;
	}
	echo "</tr>";
	//-------------//
}
$_SESSION["stage"]=$stage;   //set session variable to stage

$conn->close();             //close connection

//create your level text//
//text above options//
echo "<map_text>";
echo"create your level";
echo "</map_text>";
//------//	

//map legend//
//text above options//
echo "<key_text>";
echo"map legend";
echo "</key_text>";
//------//	

//options//
//text above options//
echo "<options_text>";
echo"options";
echo "</options_text>";
//------//	

echo "<img src='map_key.png' alt='key'>";
echo "<a class='button_options' href='home_page.php' style='vertical-align:middle'><span>return </span></button_options>";
?>
<br />
</table>
</BODY>
</HTML>