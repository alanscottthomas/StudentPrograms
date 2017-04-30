/*

Name: Mesa Spottedcorn, Kevin Magee, Alan Thomas

Class: CSI415

Assignment: Lab5 - NerdCraft

Purpose: This progam allows a user to utilize map information stored in a DB to play a game. Their user information is persistant.

Notes: None
*/



package lab5;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;
import java.util.regex.Pattern;


public class Lab5 {
    static Boolean unlocked=false;                        //variable to determine if our chest has been opened. 
   
    
//METHOD TO PRINT THE MENU FOR THE USER//
    public static void main(String[] args) throws ClassNotFoundException, SQLException 
    {
        Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
        System.out.print("\n\n");
        System.out.print("==========MENU==========\n");
        System.out.print("(A) to start a new game\n(B) continue an old game \n(Q) to exit\n");  //printing menu
        System.out.print("\n=========================\n");
        System.out.print("Input: ");

        Pattern valid_ans = Pattern.compile("[aA-zZ]");                                 //input checking
        while (!user_input.hasNext(valid_ans))                                          //input validation for menu selection
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter menu option: ");
            user_input.next();
        }
        char ans = user_input.next(".").charAt(0);                                      //placing the user's input into a char
        //SWITCH STATEMNT FOR USER SELECTION//
        switch (ans) {

            //start new game
            case 'a':
            case 'A':
                new_game();
                break;

            //continue old game
            case 'b':
            case 'B':
                old_game();
                break;

            //quit    
            case 'q':
            case 'Q':
                break;
            //default statement
            default:
                System.out.println("\n-Invalid Selection-");
                main(null);                                                             
            //END SWITCH//               
        } 
    }
    





    //method to start a new game
    public static void new_game() throws ClassNotFoundException, SQLException
    {
        Boolean name_check=false;
        
        Scanner user_input = new Scanner(System.in); 
        System.out.print("Enter your desired username(alpha only, do not exceed 50 characters): ");          //printing username info
        Pattern valid_name = Pattern.compile("[aA-zZ]*{1,50}");                                              //kleene
        while(!user_input.hasNext(valid_name))                                                               //if input isn't valid ask again
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the last name: ");
            user_input.next();  
        }
        String name = user_input.next();                                                                    //save user input
        
        //calling the name check method to see if this player is in the DB already
        name_check=check_name(name);
        
        //name does not exists
        if(name_check==false)
        {
            make_player(name);       //sending player name to be inserted into the DB
            System.out.print("\n-Your hero has been created! Welcome to World of NerdCraft!-\n");  //Why have a social life when you have World of NerdCraft?
            start_game(name);
        }
        
        //name is already in the DB, do not pass go
        else if(name_check==true)
        {
            System.out.print("\n-Sorry, but the Dungeon Master says this hero is already in the realm-\n");
            main(null); //return the user to the main menu
        }     
    }
    
    
    
    
    //method to continue a game
     public static void old_game() throws ClassNotFoundException, SQLException
    {
        Boolean name_check=false;
        
        Scanner user_input = new Scanner(System.in); 
        System.out.print("Enter your hero's name: ");                                       //get name
        Pattern valid_name = Pattern.compile("[aA-zZ]*{1,50}");                             //kleene
        while(!user_input.hasNext(valid_name))                                              //if invalid input
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the last name: ");
            user_input.next();  
        }
        String name = user_input.next();                                                   //saving user input
        
        //calling the name check method to see if this player is in the DB already
        name_check=check_name(name);
        
        //name does not exists
        if(name_check==false)
        {
            System.out.print("\n-Your hero cannot be found; the Skeleton King may have devoured them! -\n");  //Why have a social life when you have World of NerdCraft?
            main(null);
        }
        
        //found the player
        else if(name_check==true)
        {
            System.out.print("\n-Your hero has been found, loading your game world now-\n");
            start_game(name); //found the user, call stat game with their data
        }      
    }
     
     //loading the location data of the player
     public static void start_game(String name) throws ClassNotFoundException, SQLException
     {
                String sql = "SELECT * FROM player_tbl WHERE name=?";  //creating a string to use for the select statement
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getLong(3)==0)               //means this a new player
                            {
                               find_start(name,rs.getInt(1));
                               
                            }
                            else
                            {
                              move(name,rs.getInt(1),rs.getInt(3));     //calling move with the user information
                            }
                        }
     conn.close();                                                       //closing con
     }
     
     
     //method to continue a game
     public static void make_player(String name) throws SQLException, ClassNotFoundException
    {
       String sql = "INSERT INTO player_tbl (name)" + "VALUES (?)";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                //Statement st = conn.createStatement();
                preparedStatement.executeUpdate();                                                                         //pushing the INSERT command to the DB    
                conn.close();                                                                                              //close con
    }
     
    

//method to move the player to different rooms
     public static void move(String name,Integer player_id, Integer room) throws ClassNotFoundException, SQLException
    {
                update_player_location(name,room);                                                                         //saving player's current location so they can continue later
        
        
                String room_string=Integer.toString(room);                                                                //convert int to string
                String sql = "SELECT * FROM contents_tbl WHERE room_id=?";  //creating a string we'll use to select contents
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, room_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                Boolean key=false; 
                Boolean visited;
                visited=check_visited(name,player_id,room);                                                               //set bool according to info we saved into vesited table
                                                                                             
                //checking what is in the current room
                //3-enemy, 4-key_, 5-chest, 6-start, 7-end
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(3)==1)          //if enemy
                            {
                               if(visited==false)
                               {
                                   enemy_art();
                                   System.out.print("\n-There's a Murloc in this room! After a struggle you are able to fend them off! -\n");   
                               }
                               else
                               {
                                 System.out.print("\n-There's the remains of a Murloc in this room, he's starting to smell funny. -\n");   
                               } 
                                                             
                            }
                            
                            if(rs.getInt(4)==1)         //if key
                            {
                               if(visited==false)
                               {
                                 key_art();
                                   System.out.print("\n-There's a key in this room! You quickly stuff it in your bag of holding.-\n");   
                                 update_inventory(player_id,room,4);
                               }
                               else
                               {
                                 System.out.print("\n-Nothing left here, just the dusty outline of an old key.. -\n");   
                               }                               
                            }
                            
                             if(rs.getInt(5)==1)       //if chest
                            {
                               if(visited==false)
                               {
                                 System.out.print("\n-There's a chest here!-\n");   
                                 key=check_key(name,player_id);
                                 if(key==true)
                                 {
                                   chest_open_art();
                                     System.out.print("\n-You unlock the chest with a key and find the answer to life!-\n");   
                                 unlocked=true;
                                 }
                                 
                                  if(key==false)
                                 {
                                   System.out.print("\n-Hmm...better find a key to open this!-\n");  
                                   //unlocked=false;
                                 }
                                         
                               }
                                                            
                            if(visited==true)
                             {
                                
                                 key=check_key(name,player_id);
                                 System.out.print("\n-There's that pesky chest again!-\n");
                                 if(unlocked==false)
                                 {
                                    if(key==true)
                                    {
                                        chest_open_art();
                                        System.out.print("\n-You unlock the chest with a key and find the answer to life!-\n");
                                        unlocked=true;
                                        
                                    }
                                    
                                    if(key==false)
                                    {
                                      System.out.print("\n-Hmmm...you still need to find the key-\n"); 
                                    }
                                 }
                                else if(unlocked==true)
                                 {
                                     chest_open_art();
                                     System.out.print("\n-Not as exciting after it's already been unlocked-\n"); 
                                 }

                            }
  
                        }
                              if(rs.getInt(6)==1)                   //if start
                            {
                               if(visited==false)
                               {
                                 System.out.print("\n-This is where it all begins, let's explore! -\n");   
                               }
                               else
                               {
                                 System.out.print("\n-You are at the start again...better find where this maze ends.-\n");   
                               
                               } 
                                                             
                            }
                             
                             if(rs.getInt(7)==1)   //if end
                            {
                               
                                 System.out.print("\n-You found the exit! 'C' to continue playing, 'E' to exit-\n");   
                                 
                                 System.out.print("Input: ");

        
                                    Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
                                 char ans = user_input.next().charAt(0);                                      //placing the user's input into a char
                                //SWITCH STATEMNT FOR USER SELECTION//
                                switch (ans) {
                                    case 'c':
                                    case 'C':
                                        get_directions(name,player_id,room); 
                                        //break;

                                    case 'e':
                                    case 'E':
                                        conn.close();
                                        System.exit(0);
                                        break;
                                    default:
                                        System.out.println("\n-Invalid Selection-");
                                }
                               
                                                             
                            }
     
                 
              update_visited(name,player_id,room);                 //update visted table
              get_directions(name,player_id,room);                 //see where we can go from this room
              conn.close();                                        //close con
                 
    }
    }
     
    

//update player's current location
     public static void update_player_location(String name,Integer room_id) throws ClassNotFoundException, SQLException
     {
            String sql = "update player_tbl set current_room = ?  where name= ?";          //creating the string we'll use to execute the update
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";    //DB connection info
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");           //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);       
            preparedStatement.setInt(1, room_id);
            preparedStatement.setString(2, name);
            Statement st = conn.createStatement();
            preparedStatement.executeUpdate();                                  //pushing the statement to the DB
            conn.close();   
     }






//get the direction(s) you can move 
    public static void get_directions(String name,Integer player_id, Integer room_id) throws ClassNotFoundException, SQLException
    {
      String room_id_string=Integer.toString(room_id);
                String sql = "SELECT * FROM rooms_tbl WHERE room_id=?";  //creating a string we'll use to select from the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, room_id_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
               
                //ints to store room ids for navigation
                int north=0;
                int south=0;
                int west=0;
                int east=0;
                 int count=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(2)!=0)
                            {
                             System.out.print("\n-You can move 'n'orth -\n");
                             north=rs.getInt(2);
                               
                            }
                            
                            if(rs.getInt(3)!=0)
                            {
                             System.out.print("\n-You can move 's'outh -\n");
                             south=rs.getInt(3);  
                            }
                            
                            if(rs.getInt(4)!=0)
                            {
                             System.out.print("\n-You can move 'w'est -\n");
                             west=rs.getInt(4);
                               
                            }
                            
                            if(rs.getInt(5)!=0)
                            {
                             System.out.print("\n-You can move 'e'ast -\n");
                             east=rs.getInt(5);
                               
                            }
                           System.out.print("\n-'Q' to quit -\n");
                        }
                 
                 
                 
                 
                 Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
        
        System.out.print("Input: ");

        
        char ans = user_input.next().charAt(0);                                      //placing the user's input into a char
        //SWITCH STATEMNT FOR USER SELECTION//
        switch (ans) {

            //start new game
            
            case 'n':
            case 'N':
                if(north==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,north);
                }
                break;

            //continue old game
            case 's':
            case 'S':
                if(south==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,south);
                }
                break;

            //quit    
            case 'w':
            case 'W':
                if(west==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,west);
                }
                break;
                
            case 'e':
            case 'E':
                if(east==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,east);
                }
                break;
                
            case 'q':
            case 'Q':
                conn.close();
                System.exit(0);
                
                
            //default statement
            default:
                System.out.println("\n-Invalid Selection-");
                get_directions(name,player_id,room_id);               
// main(null);                                                             //I don't like calling main recursively, but I couldn't get the switch to work otherwise.
            //END SWITCH//               
        } 
                 
                 
                 
                 
                 conn.close();
                
    }
     
     
     
//update player's inventory function
     public static void update_inventory(Integer player_id,Integer room,Integer item) throws ClassNotFoundException, SQLException
     {
                String player_id_string=Integer.toString(player_id);
                String room_string=Integer.toString(room);
                String sql = "INSERT INTO inventory_tbl (player_id, key_, chest, room)" + "VALUES (?,?,?,?)";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                if(item==4)
                {
                 preparedStatement.setString(1, player_id_string);
                 preparedStatement.setString(2, "1");
                 preparedStatement.setString(3, "0"); 
                 preparedStatement.setString(4, room_string); 
                 
                }
                
                if(item==5)
                {
                 preparedStatement.setString(1, player_id_string);
                 preparedStatement.setString(2, "0");
                 preparedStatement.setString(3, "1"); 
                 preparedStatement.setString(4, room_string); 
                
                }
                
                preparedStatement.executeUpdate(); 
                //Statement st = conn.createStatement();
                                                                                        //pushing the INSERT command to the DB    
                conn.close();  
     }


//check for key
public static Boolean check_key(String name, Integer player_id) throws SQLException, ClassNotFoundException
     {
                String player_id_string=Integer.toString(player_id);
                String sql = "SELECT * FROM inventory_tbl WHERE player_id=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, player_id_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 int count=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(3)==1)
                            {
                              count++;
                               
                            }
                           
                        }
                 conn.close();
                 if(count>0)
                 {
                     return true;
                 }
                 
                 else
                 {
                     return false;
                 }
     }     
     
     
     



//check if the player has been to the current room
     public static void update_visited(String name,Integer player_id,Integer room) throws ClassNotFoundException, SQLException
     {
                String player_id_string=Integer.toString(player_id);
                String room_string=Integer.toString(room);
                String sql = "INSERT INTO visited_tbl (player_id,room_number)" + "VALUES (?,?)";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, player_id_string);
                preparedStatement.setString(2, room_string);
                //Statement st = conn.createStatement();
                preparedStatement.executeUpdate();                                                                         //pushing the INSERT command to the DB    
                conn.close();  
     }
     

     //check if the player has been to the current room
     public static Boolean check_visited(String name, Integer player_id, Integer room_id) throws SQLException, ClassNotFoundException
     {
                String player_id_string=Integer.toString(player_id);
                String sql = "SELECT * FROM visited_tbl WHERE player_id=?";  //creating a string we'll use to select from the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, player_id_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 int count=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(3)==room_id)
                            {
                              count++;
                               
                            }
                           
                        }
                 conn.close();
                 if(count>0)
                 {
                     return true;
                 }
                 
                 else
                 {
                     return false;
                 }
     }
     
     
     //method to find the starting point 
     public static void find_start(String name, Integer player_id) throws SQLException, ClassNotFoundException
     {
         String sql = "SELECT * FROM contents_tbl WHERE start=?";  //creating a string we'll use to select from the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, "1");
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(6)==1)
                            {
                               move(name,player_id,rs.getInt(2)); //call move function with the player name,player id and starting room
                               
                            }
                            
                        }
     conn.close();
     }
     
     


    //method to check if the name is in the DB
      public static boolean check_name(String name) throws ClassNotFoundException, SQLException
    {
        String sql = "SELECT * FROM player_tbl WHERE name=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                int count=0;
                
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                            count++; 
                        }
                 
                
                 conn.close(); 
                 //we didn't find this username, return false so the user can make it
                 if (count==0)
                 {
                     return false;
                 }
                 
                 //this username already exists, return true and do not let them pass go
                 else
                 {
                     return true;
                 }              
    } 



static public void key_art()
{
   
    System.out.println("\n 8 8 8 8                     ,ooo.");
    System.out.println(" 8a8 8a8                    oP   ?b");
    System.out.println("d888a888zzzzzzzzzzzzzzzzzzzz8     8b");
    System.out.println(" `\"\"^\"\"'                    ?o___oP'");
}


static public void chest_open_art()
{
   
    System.out.println("\n         __________");
    System.out.println("        /\\____;;___\\");
    System.out.println("       | /         /");
    System.out.println("       `. ())oo() .");
    System.out.println("        |\\(%()*^^()^\\");
    System.out.println("       %| |-%-------|");
    System.out.println("      % \\ | %  ))   |");
    System.out.println("      %  \\|%________|");
    System.out.println("       %%%%");
}



static public void enemy_art()
{
     System.out.println("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X");
     System.out.println("|                           ,,'``````````````',,                            |");
     System.out.println("X                        ,'`                   `',                          X");
     System.out.println("|                      ,'                         ',                        |");
     System.out.println("X                    ,'          ;       ;          ',                      X");
     System.out.println("|       (           ;             ;     ;             ;     (               |");
     System.out.println("X        )         ;              ;     ;              ;     )              X");
     System.out.println("|       (         ;                ;   ;                ;   (               |");
     System.out.println("X        )    ;   ;    ,,'```',,,   ; ;   ,,,'```',,    ;   ;               X");
     System.out.println("|       (    ; ',;   '`          `',   ,'`          `'   ;,' ;              |");
     System.out.println("X        )  ; ;`,`',  _--~~~~--__   ' '   __--~~~~--_  ,'`,'; ;     )       X");
     System.out.println("|     (    ; `,' ; :  /       \\~~-___-~~/       \\  : ; ',' ;     (        |");
     System.out.println("X      )   )',  ;   -_\\  o    /  '   '  \\    o  /_-   ;  ,'       )   (   X");
     System.out.println("| (     (   (   `;      ~-____--~'       '~--____-~      ;'  )     (     )  |");
     System.out.println("X  )     )   )   ;            ,`;,,,   ,,,;',            ;  (       )   (   X");
     System.out.println("| (     (   (  .  ;        ,'`  (__ '_' __)  `',        ;  . )     (     )  |");
     System.out.println("X  )   \\/ ,\".). ';    ,'`        ~~ ~~        `',    ;  .(.\", \\/  )   ( X");
     System.out.println("| (   , ,'|// / (/ ,;  '        _--~~-~~--_        '  ;, \\)    \\|', ,  )  |");
     System.out.println("X ,), \\/ \\|  \\\\,/  ;;       ,; |_| | |_| ;,       ;;  \\,//  |/ \\/ , , X");
     System.out.println("|                            ;_| : `~'~' : |_;                              |");
     System.out.println("X#(,'  )  #\\ \\##/)#;      :  `\\/       \\/   :     ;#(\\##/ /#///(  ',)#,X");
     System.out.println("|| ) | \\ |/ /#/ |#( \\; ;      :          ;     ; ;/ )#| \\#\\ \\| / | ( |) |");
     System.out.println("X\\ |.\\\\ |\\_/#| /#),,`     ;./\\_     _/\\.;    ; `,,(#\\ |#\\_/| //.| / ,X");
     System.out.println("| \\\\_/# |#\\##/,,'`       ;   ~~--|~|~|--~~  ;       `',,\\##/#| #\\_// \\/|");
     System.out.println("X  ##/#  #,,'`            ;        ~~~~~        ;            `',,#  #\\##  //X");
     System.out.println("|####@,,'`                 `',               ,'`                 `',,@####| |");
     System.out.println("X#,,'`                        `',         ,'`                        `',,###X");
     System.out.println("|'                               ~~-----~~                               `' |");
     System.out.println("X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X");
     
}


}
