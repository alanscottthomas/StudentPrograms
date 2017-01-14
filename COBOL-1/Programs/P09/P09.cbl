       identification division.
       program-id. REPORTMAKER.
       author. Alan Thomas.
       date-compiled. 11/25/2015.
      *THIS PROGRAM IS SUPPOSED TO READ 3 DIFFERENT FILES INTO
      *TABLES. THESE TABLES WOULD THAN MATCH THE VALUES AND PRINT THE
      *RESULTS TO AN OUTPUTFILE. I WAS UNABLE TO GET THE PROGRAM TO WORK
      *FULLY. I THINK I'M ON THE RIGHT TRACK, BUT OVERALL WAS UNABLE TO
      *WRITE A PROGRAM THAT WORKED AS WAS INTENDED. THIS IS THE WORK I
      *HAVE DONE THUS FAR.

      *MY MAJOR ISSUE WAS GETTING NULL RESULTS WHEN WRITING TO THE FILE.
      *I ATTRIBUTE THIS TO INCORRECTLY READING THE FILES SOMEHOW.

      *I ALSO ENCOUNTERED AN OUT OF BOUNDS ERROR, WHICH I FIGURED
      *WAS THE PROGRAM ATTEMPTING TO READ INFORMATION THAT WAS OUT OF
      *SCOPE OF THE TABLE. I COMMENTED OUT THE ELSE STATEMENT ON LINE
      *242 TO AT LEAST LET ME RUN THE PROGRAM, ALBEIT PARTIALLY.


       ENVIRONMENT DIVISION.
           INPUT-OUTPUT SECTION.
               FILE-CONTROL.
               SELECT FILE1 ASSIGN TO "C:\COBOL\P09D01.DAT"
               organization is line sequential.

               SELECT FILE2 ASSIGN TO "C:\COBOL\P09DDT.DAT"
               organization is line sequential.

               SELECT FILE3 ASSIGN TO "C:\COBOL\P09DPT.DAT"
               organization is line SEQUENTIAL.

               SELECT OUTPUTFILE ASSIGN TO
                  "C:\COBOL\P09R01.RPT"
                       organization is line sequential.

       DATA DIVISION.
           FILE SECTION.
           FD FILE1.
           01 FILE1-PICS.
             05 EMPLOYEE-SSN PIC 9(9).
             05 EMPLOYEE-NAME PIC X(20).
             05 EMPLOYEE-SALARY PIC 9(6).
             05 EMPLOYEE-CAMPUS PIC 9.
             05 EMPLOYEE-DEPARTMENT PIC 99.
             05 EMPLOYEE-POSITION PIC 999.


           FD FILE2.
           01 FILE2-PICS.
               05 DEPARTMENT-CODE PIC 99.
               05 DEPARTMENT-NAME PIC X(10).

           FD FILE3.
           01 FILE3-PICS.
               05 POSITION-CODE PIC 9(3).
               05 POSITION-NAME PIC X(15).

           FD OUTPUTFILE.
               01 PRINT-AREA PIC X(132).

       WORKING-STORAGE SECTION.

           01 PRINT-FIELDS.
           05 PAGE-COUNT       PIC S9(3)   VALUE ZERO.
           05 LINES-ON-PAGE    PIC S9(3)   VALUE +99.
           05 LINE-COUNT       PIC S9(3)   VALUE +99.
           05 SPACE-CONTROL    PIC S9.
           05 LINES-PRICE      pic 9(6)V99.



       01 HEADING-LINE-1.

          05 FILLER           PIC x(7) value "EMP. ID".

          05 FILLER           PIC x(2) value SPACE.
          05 FILLER           PIC x(8) value "EMPLOYEE".
          05 FILLER           PIC x(4) value SPACE.
          05 FILLER           PIC x(6) value "SALARY".
          05 FILLER           PIC x(10) value SPACE.
          05 FILLER           PIC x(6) value "CAMPUS".
          05 FILLER           PIC x(4) value SPACE.
          05 FILLER           PIC x(10) value "DEPARTMENT".
          05 FILLER           PIC x(4) value SPACE.
          05 FILLER           PIC x(8) value "POSITION".




       01 SWITCH PIC X VALUE "N".
           88 ENDOFFILE    VALUE "N".
           88 PROCESSFILE    VALUE "N".
       01 XSWITCH PIC X VALUE "N".



       01  TCAMPUSTABLEDEFS.
           05  FILLER    PIC X(10)  VALUE "UPSTATE".
           05  FILLER    PIC X(10)  VALUE "DOWNSTATE".
           05  FILLER    PIC X(10)  VALUE "CITY".
           05  FILLER    PIC X(10)  VALUE "MELVILLE".
           05  FILLER    PIC X(10)  VALUE "HUNTINGTON".
       01  T-CAMPUS REDEFINES TCAMPUSTABLEDEFS.
           05 TCAMPUSTABLE OCCURS 5 TIMES.
              10 TCAMPUSNAME PIC X(10).

       01  T-DEPARTMENT.
           05 TDEPARTMENTTABLE OCCURS 25 TIMES INDEXED BY IX.
              10 TDEPARTMENTCODE PIC 99.
              10 TDEPARTMENTNAME PIC X(10).

        01  T-POSITIONS.
           05 TPOSITIONTABLE OCCURS 50 TIMES INDEXED BY IY.
              10 TPOSITIONCODE PIC 999.
              10 TPOSITIONNAME PIC X(10).

       01 I PIC 9(2)  BINARY.

       01 DETAILLINE.
           05 SSN PIC 999B99B9999.
           05 FILLER PIC X(5) VALUE SPACES.
           05 NAME PIC X(20).
           05 FILLER PIC X(5) VALUE SPACES.
           05 SALARY PIC $ZZZ,ZZ9.
           05 FILLER PIC X(5) VALUE SPACES.
           05 CAMPUS PIC X(10).
           05 FILLER PIC X(5) VALUE SPACES.
           05 DEPARTMENT PIC X(10).
           05 FILLER PIC X(5) VALUE SPACES.
           05 EMP-POSITION PIC X(10).




       PROCEDURE DIVISION.
       000-MAIN.
           OPEN  OUTPUT OUTPUTFILE.
           PERFORM 010-INIT.


           STOP RUN.


       010-INIT.


           PERFORM 020-LOADDEPARTMENTS.
           PERFORM 030-LOADPOSITIONS.
           PERFORM 090-PRINT-HEADING-LINES.



           SET PROCESSFILE TO TRUE.
           PERFORM 100-LOOP UNTIL XSWITCH = "Y".


           *>CLOSE  FILE1 FILE2 FILE3.
          *> CLOSE  OUTPUTFILE.




       020-LOADDEPARTMENTS.
           OPEN INPUT FILE2.

           SET PROCESSFILE TO TRUE.
           SET   I TO 1.
           PERFORM UNTIL ENDOFFILE
               READ FILE1
                 AT END
                   SET ENDOFFILE TO TRUE
                 NOT AT END
                   SET I UP BY 1
                   MOVE FILE2-PICS TO TDEPARTMENTTABLE (I)
                   IF I = 26
                       SET ENDOFFILE TO TRUE
                END-IF
               END-READ
           END-PERFORM.
           CLOSE FILE2.



       030-LOADPOSITIONS.

           SET PROCESSFILE TO TRUE.
           SET   I TO 1.
           PERFORM UNTIL ENDOFFILE
               READ FILE3
                 AT END
                   SET ENDOFFILE TO TRUE
                 NOT AT END
                   SET I UP BY 1
                   MOVE FILE3-PICS TO TPOSITIONTABLE (I)
                   IF I = 51
                       SET ENDOFFILE TO TRUE
                   END-IF

           END-PERFORM.





       090-PRINT-HEADING-LINES.

           ADD 1 TO PAGE-COUNT.

           MOVE HEADING-LINE-1 TO PRINT-AREA.
           WRITE PRINT-AREA AFTER ADVANCING PAGE.
           MOVE ZERO TO LINE-COUNT.
           MOVE 2 TO SPACE-CONTROL.

       100-LOOP.
          OPEN INPUT FILE3.
           READ FILE3
             AT END
               SET ENDOFFILE TO TRUE
            NOT AT END
               PERFORM 110-DETAILPROCESSING.
               CLOSE FILE3.







       *>110 ISN'T WORKING.
       110-DETAILPROCESSING.
           display "1".
           MOVE EMPLOYEE-SSN TO SSN.
           display "2".
           MOVE EMPLOYEE-NAME TO NAME.
           display "3".
           MOVE EMPLOYEE-SALARY TO SALARY.
           display "4".
           IF EMPLOYEE-CAMPUS > 5
               MOVE "UNKNOWN" TO CAMPUS
             else if EMPLOYEE-CAMPUS = "2"
                 MOVE "TESTING" TO CAMPUS
            *>ELSE
              *> MOVE TCAMPUSNAME(EMPLOYEE-CAMPUS) TO CAMPUS.


           SEARCH TDEPARTMENTTABLE
                  AT END
                    MOVE "UNKNOWN" TO DEPARTMENT
                  WHEN EMPLOYEE-DEPARTMENT = TDEPARTMENTCODE (IX)
                    MOVE TDEPARTMENTNAME(IX) TO DEPARTMENT.

           SEARCH TPOSITIONTABLE
                  AT END
                      MOVE "UNKNOWN" TO EMP-POSITION
                  WHEN EMPLOYEE-POSITION = TPOSITIONCODE (IY)
                   MOVE TPOSITIONNAME(IY) TO EMP-POSITION.

          WRITE PRINT-AREA FROM DETAILLINE.

         STOP RUN.
