       identification division.
       program-id. REPORTMAKER.
       author. Alan Thomas.
       date-compiled. 10/12/2015.
      *THIS PROGRAM IS DESIGNED WITH THE PURPOSE OF READING A DATA FILE
      *CONSISTING OF CLIENT INFORMATION SUCH AS; NAME, NUMBER, AND
      *ACCOUNT BALANCE. IT TAKES THIS INFORMATION AND WRITES A RECORD 
      *IN AN EASY TO READ FORMAT THAN COMPUTES PRICES DEPENDING ON
      *APPLICABLE DISCOUNTS (10% AND 20%). 


       ENVIRONMENT DIVISION.
           INPUT-OUTPUT SECTION.
               FILE-CONTROL.
               SELECT THEIRFILE ASSIGN TO "E:\programming\P05D.dat"
               organization is line sequential.

               SELECT OURFILE ASSIGN TO "E:\programming\P05R.RPT"
               organization is line sequential.

       DATA DIVISION.
           FILE SECTION.
           FD THEIRFILE.
           01 THEIRFILE-PICS.
             05 EMP-PURCHASER-NUMBER       PIC x(5).
             05 EMP-PURCHASER-NAME         PIC x(20).
             05 EMP-PRICE                  pic 9(7).

       FD OURFILE.
           01 PRINT-AREA                   PIC X(132).



       WORKING-STORAGE SECTION.
       01 SWITCHES.
           05 EOF-SWITCH PIC X VALUE "N".
       
       01 PRINT-FIELDS.
           05 PAGE-COUNT       PIC S9(3)   VALUE ZERO.
           05 LINES-ON-PAGE    PIC S9(3)   VALUE +99.
           05 LINE-COUNT       PIC S9(3)   VALUE +99.
           05 SPACE-CONTROL    PIC S9.
           05 LINES-PRICE      pic 9(6)V99.   

       01 CURRENT-DATE-AND-TIME.
           05 CD-YEAR          PIC 9999.
           05 CD-MONTH         PIC 99.
           05 CD-DAY           PIC 99.

       01 HEADING-LINE-1.
          05 FILLER           PIC x(7) value "Date:".
          05 HL1-MONTH        PIC 9(2).
          05 FILLER           PIC x(1) value "/".
          05 HL1-DAY          PIC 9(2).
          05 FILLER           PIC x(1) value "/".
          05 HL1-YEAR         PIC 9(4).
          05 FILLER           PIC x(36) value SPACE.
          05 FILLER           PIC x(20) value "-PURCHASER PROGRAM-".
          05 FILLER           PIC x(40) value SPACE.
          05 FILLER           PIC x(5) value "PAGE:".
          05 HL1-PAGE-NUMBER  PIC zzz.
          05 FILLER           PIC x(52) value SPACE.

       01 HEADING-LINE-2.
           05 FILLER           PIC x(132) value all "-".

       01 HEADING-LINE-3.
               05 FILLER           PIC x(9) value "PURCHASER".


       01 HEADING-LINE-4.
           05 FILLER           PIC x(4) value "NUM".
           05 FILLER           PIC x(20) value "           NAME".
           05 FILLER           PIC x(21) value "          PRICE".
           05 FILLER           PIC x(25) value "PAID DAYS 1-30".
           05 FILLER           PIC x(25) value "PAID DAYS 31-60".
           05 FILLER           PIC x(29) value SPACE.

       01 PURCHASER-LINE.
           05 EL-PURCHASER-NUMBER      PIC x(5).
           05 FILLER                   PIC X(4) value spaces.
           05 EL-PURCHASER-NAME        PIC x(20).
           05 FILLER                   PIC X(4) value spaces.
           05 EL-PRICE2                pic Z(1)z(2),z(3).99.
           05 FILLER                   PIC X(7) value spaces.
           05 EL-PRICE4                pic Z(1)z(2),z(3).99.
           05 FILLER                   PIC X(15) value spaces.
           05 EL-PRICE3                pic Z(1)z(2),z(3).99.

       01 GRAND-TOTAL-LINE.
           05 PRICE                    pic 9999999V99.
           05 PRICE-TOTAL              pic 9999999V99.
           05 TENPERCENT               pic v999 value .1.
           05 TWENTYPERCENT            pic v999 value .2.
           05 EL-PRICE                 pic 9(6)V99.

       01 GRAND-TOTAL-LINE-PRINT.
           05 NEW-PRICE                pic 9(7)v99.
           05 DECREASE-PRICE           pic 9(7)v99.
           
      
        
       01 BYE.
           05 FILLER                   PIC X(59) VALUE ALL "-".
           05 FILLER                   PIC X(14) VALUE "END-OF-REPORT".
           05 FILLER                   PIC X(59) VALUE ALL "-".

       procedure division.

       000-MAIN.  
          OPEN INPUT THEIRFILE
               OUTPUT OURFILE.
          PERFORM 100-FORMAT-REPORT-HEADING.
          PERFORM 200-PREPARE-PURCHASER-LINES
                   UNTIL EOF-SWITCH = "Y".
           accept eof-switch.
           set PAGE-COUNT to 1.
           PERFORM 999-END.
           CLOSE THEIRFILE
                   OURFILE.
           STOP RUN.


       100-FORMAT-REPORT-HEADING. *>P79
           MOVE FUNCTION CURRENT-DATE TO CURRENT-DATE-AND-TIME.
           MOVE CD-MONTH TO HL1-MONTH.
           MOVE CD-DAY TO HL1-DAY.
           MOVE CD-YEAR TO HL1-YEAR.

      *----READING FILE----
       200-PREPARE-PURCHASER-LINES. 
           PERFORM 210-READ-PURCHASER-RCD.
           IF EOF-SWITCH = "N"
               PERFORM 220-PRINT-PURCHASER-LINE.



       210-READ-PURCHASER-RCD. *>PARA TO READ INPUT FILE
           READ THEIRFILE
               AT END
                   MOVE "Y" TO EOF-SWITCH
                END-READ.
                   
      *----END READING FILE---- 
       
      *----PRINTING LINES TO REPORT---- 
       220-PRINT-PURCHASER-LINE. 
           IF LINE-COUNT >= LINES-ON-PAGE
               PERFORM 230-PRINT-HEADING-LINES.
           PERFORM 310-PURCHASER-TOTALS.
           MOVE EMP-PURCHASER-NUMBER TO EL-PURCHASER-NUMBER.
           ADD EMP-PRICE TO EL-PRICE GIVING EL-PRICE2.
           MOVE EMP-PURCHASER-NAME TO EL-PURCHASER-NAME.
           MOVE PURCHASER-LINE TO PRINT-AREA.
           MOVE 0 TO SPACE-CONTROL.
           display "printing purchase lines".
           WRITE PRINT-AREA AFTER ADVANCING SPACE-CONTROL LINES.
           ADD 1 TO LINE-COUNT.



      * ----PRINT HEADER----
       230-PRINT-HEADING-LINES.
           ADD 1 TO PAGE-COUNT.
           MOVE PAGE-COUNT TO HL1-PAGE-NUMBER
           MOVE HEADING-LINE-1 TO PRINT-AREA.
           WRITE PRINT-AREA AFTER ADVANCING PAGE.
           MOVE HEADING-LINE-3 TO PRINT-AREA.
           WRITE PRINT-AREA AFTER ADVANCING 0 LINES.
           MOVE HEADING-LINE-4 TO PRINT-AREA.
           WRITE PRINT-AREA AFTER ADVANCING 0 LINES.
           MOVE HEADING-LINE-2 TO PRINT-AREA.
           WRITE PRINT-AREA AFTER ADVANCING 0 LINES.
           MOVE ZERO TO LINE-COUNT.
           MOVE 2 TO SPACE-CONTROL.
      *----END PRINTER HEADER----
      
      *----START DISCOUNT COMPUTATIONS----     
       310-PURCHASER-TOTALS.
           COMPUTE DECREASE-PRICE ROUNDED = EMP-PRICE * TENPERCENT
           SUBTRACT DECREASE-PRICE FROM EMP-PRICE GIVING EL-PRICE3.


           COMPUTE DECREASE-PRICE ROUNDED = EMP-PRICE * TWENTYPERCENT
           SUBTRACT DECREASE-PRICE FROM EMP-PRICE GIVING EL-PRICE4.
      *----END DISCOUNT COMPUTATIONS----     
      
      *----WRITE EOR TO REPORT----
       999-END.
           MOVE BYE TO PRINT-AREA.
           WRITE PRINT-AREA.
      *----END WRITE EOR TO REPORT----