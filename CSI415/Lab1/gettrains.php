<?php
//echo '<body style="font-family:Arial;">';
echo '<body style="font-family:Arial;background-color:rgba(0, 37, 60, .35); color: #FFFFFF ;padding: 10px 100px; border-radius: 1px">';
require_once('../../mysqli_connect_trains.php');

$query = "SELECT * FROM trains_tbl";

$response = @mysqli_query($dbc, $query);
if($response){

    echo '<table align="left"
    cellspacing="5" cellpadding="8">

    
    <td align="left"><b>Train</b></td>    
    <td align="left"><b>Departed</b></td>
    <td align="left"><b>Destination</b></td>
    <td align="left"><b>Seconds Untill Arrival</b></td>';

    while($row = mysqli_fetch_array($response)){
       echo '<tr><td align="center">'.
       $row['name'] . '</td><td align="center">'.
       $row['departure'] . '</td><td align="center">'.
       $row['destination'] . '</td><td align="center">'.
       $row['location'] . '</td><td align="center">';
echo '</tr>';


}
echo '</table>';
}

     else
        {
           echo "Couldn't execute query";
           echo mysqli_error($dbc);
         }


mysqli_close($dbc);


?> 



