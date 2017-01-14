       identification division.
       program-id. TRIG-CALC.
       author. Alan Thomas.
       date-compiled. 10/26/2015.
      *function: Accept and compute/display SINE,COSINE & TANGENT
      *input files None
      *output files None
      *printer ouput None



       data division.
       working-storage section.
       01 p-day-in  pic 9(09).
       01 p-dow-out pic x(03).
       01 p-genter  pic 9(03).
       01 SWITCH PIC X VALUE 'N'.


       01  CURRENT-DATE-FIELDS.
             05  WS-CURRENT-DATE.
                 10  WS-CURRENT-YEAR    PIC  9(4).
                 10  WS-CURRENT-MONTH   PIC  9(2).
                 10  WS-CURRENT-DAY     PIC  9(2).

        01 enter-date                   pic 9(8).
        01 enter-date-x redefines enter-date.
           05 mm pic 9(2).
           05 dd pic 9(2).
           05 yyyy pic 9(4).

       01 WORK-DATE PIC 9(8).
       01  work-date-X.
           05 yyyy pic 9(4).
           05 mm pic 9(2).
           05 dd pic 9(2).


       procedure division.

       000-MAIN.
         PERFORM 100-GETDATE
               UNTIL SWITCH = 'Y'.
           DISPLAY "-EXITING PROGRAM-".
           STOP RUN.

      *-BEGIN CODE TO ACCEPT AND DISPLAY USER INPUT-
       100-GETDATE.
           DISPLAY "-----------------", WS-CURRENT-MONTH ,"/",
                         WS-CURRENT-DAY ,"/", WS-CURRENT-YEAR.
           DISPLAY "mmddyyyy - Enter date (after 12/31/1601): ".  *>line to accept user date
           accept enter-date.

           move corr enter-date-x to work-date-X. *> CORRESPOND STATEMENT (USE CORR INSTEAD OF MOVE STATEMENTS)

           IF enter-date = 0 *>Checking date for LOOOP SWITCH
               MOVE 'Y' TO SWITCH

           ELSE IF enter-date > 12311601
               DISPLAY "*INVALID DEGREE ENTERED*"
               PERFORM 000-MAIN

      *-RUNNING FUNCTIONS FOR TRIG CALCS-
           ELSE
               MULTIPLY ENTER-DATE BY 0.017463292 GIVING RADIAN ROUNDED
               COMPUTE SINE_PRINT = FUNCTION SIN (RADIAN)
               COMPUTE COSINE_PRINT = FUNCTION COS (RADIAN)
               COMPUTE TANGENT_PRINT = FUNCTION TAN (RADIAN)
               DISPLAY "SINE:   ", SINE_PRINT
               DISPLAY "COSINE: ", COSINE_PRINT
               DISPLAY "TANGENT: ", TANGENT_PRINT
          END-IF.

       end program TRIG-CALC.
