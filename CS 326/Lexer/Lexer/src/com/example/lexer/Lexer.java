package com.example.lexer;

import java.io.File;    //import the file class
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class Lexer {
    /*
     * Tokenizer Function
     * Parameters: a single token(string)
     * Outputs the name of the token, its category, and its value OR an error
    */
    static void Tokenizer(String token) {
        switch(token) {
            case "output":
                System.out.println("Token category: 1, OUTPUT keyword, value \"" + token + "\"");
                break;
            case "on":
                System.out.println("Token category: 2, ON keyword, value \"" + token + "\"");
                break;
            case "create":
                System.out.println("Token category: 3, CREATE keyword, value \"" + token + "\"");
                break;
            case "constant":
                System.out.println("Token category: 4, CONSTANT keyword, value \"" + token + "\"");
                break;
            case "elseif":
                System.out.println("Token category: 5, ELSE_IF keyword, value \"" + token + "\"");
                break;
            case "me":
                System.out.println("Token category: 6, ME keyword, value \"" + token + "\"");
                break;
            case "until":
                System.out.println("Token category: 7, UNTIL keyword, value \"" + token + "\"");
                break;
            case "public":
                System.out.println("Token category: 8, PUBLIC keyword, value \"" + token + "\"");
                break;
            case "private":
                System.out.println("Token category: 9, PRIVATE keyword, value \"" + token + "\"");
                break;
            case "alert":
                System.out.println("Token category: 10, ALERT keyword, value \"" + token + "\"");
                break;
            case "detect":
                System.out.println("Token category: 11, DETECT keyword, value \"" + token + "\"");
                break;
            case "always":
                System.out.println("Token category: 12, ALWAYS keyword, value \"" + token + "\"");
                break;
            case "check":
                System.out.println("Token category: 13, CHECK keyword, value \"" + token + "\"");
                break;
            case "parent":
                System.out.println("Token category: 14, PARENT keyword, value \"" + token + "\"");
                break;
            case "blueprint":
                System.out.println("Token category: 15, BLUEPRINT keyword, value \"" + token + "\"");
                break;
            case "system":
                System.out.println("Token category: 16, NATIVE keyword, value \"" + token + "\"");
                break;
            case "is":
                System.out.println("Token category: 17, INHERITS keyword, value \"" + token + "\"");
                break;
            case "cast":
                System.out.println("Token category: 18, CAST keyword, value \"" + token + "\"");
                break;
            case "input":
                System.out.println("Token category: 19, INPUT keyword, value \"" + token + "\"");
                break;
            case "say":
                System.out.println("Token category: 20, SAY keyword, value \"" + token + "\"");
                break;
            case "now":
                System.out.println("Token category: 21, NOW keyword, value \"" + token + "\"");
                break;
            case "while":
                System.out.println("Token category: 22, WHILE keyword, value \"" + token + "\"");
                break;
            case "package":
                System.out.println("Token category: 23, PACKAGE_NAME keyword, value \"" + token + "\"");
                break;
            case "times":
                System.out.println("Token category: 24, TIMES keyword, value \"" + token + "\"");
                break;
            case "repeat":
                System.out.println("Token category: 25, REPEAT keyword, value \"" + token + "\"");
                break;
            case "else":
                System.out.println("Token category: 26, ELSE keyword, value \"" + token + "\"");
                break;
            case "returns":
                System.out.println("Token category: 27, RETURNS keyword, value \"" + token + "\"");
                break;
            case "return":
                System.out.println("Token category: 28, RETURN keyword, value \"" + token + "\"");
                break;
            case "and":
                System.out.println("Token category: 29, AND keyword, value \"" + token + "\"");
                break;
            case "or":
                System.out.println("Token category: 30, OR keyword, value \"" + token + "\"");
                break;
            case "undefined":
                System.out.println("Token category: 31, NULL keyword, value \"" + token + "\"");
                break;
            case "shared":
                System.out.println("Token category: 32, STATIC keyword, value \"" + token + "\"");
                break;
            case "action":
                System.out.println("Token category: 33, ACTION keyword, value \"" + token + "\"");
                break;
            case ":":
                System.out.println("Token category: 34, COLON, value \"" + token + "\"");
                break;
            case "integer":
                System.out.println("Token category: 35, INTEGER keyword, value \"" + token + "\"");
                break;
            case "number":
                System.out.println("Token category: 36, NUMBER keyword, value \"" + token + "\"");
                break;
            case "text":
                System.out.println("Token category: 37, TEXT keyword, value \"" + token + "\"");
                break;
            case "boolean":
                System.out.println("Token category: 38, BOOLEAN keyword, value \"" + token + "\"");
                break;
            case "use":
                System.out.println("Token category: 39, USE keyword, value \"" + token + "\"");
                break;
            case "not":
                System.out.println("Token category: 40, NOT keyword, value \"" + token + "\"");
                break;
            case "Not":
                System.out.println("Token category: 40, NOT keyword, value \"" + token + "\"");
                break;
            case "not=":
                System.out.println("Token category: 41, NOTEQUALS keyword, value \"" + token + "\"");
                break;
            case "Not=":
                System.out.println("Token category: 41, NOTEQUALS keyword, value \"" + token + "\"");
                break;
            case ".":
                System.out.println("Token category: 42, PERIOD, value \"" + token + "\"");
                break;
            case ",":
                System.out.println("Token category: 43, COMMA, value \"" + token + "\"");
                break;
            case "=":
                System.out.println("Token category: 44, EQUALITY, value \"" + token + "\"");
                break;
            case ">":
                System.out.println("Token category: 45, GREATER, value \"" + token + "\"");
                break;
            case ">=":
                System.out.println("Token category: 46, GREATER_EQUAL, value \"" + token + "\"");
                break;
            case "<":
                System.out.println("Token category: 47, LESS, value \"" + token + "\"");
                break;
            case "<=":
                System.out.println("Token category: 48, LESS_EQUAL keyword, value \"" + token + "\"");
                break;
            case "+":
                System.out.println("Token category: 49, PLUS, value \"" + token + "\"");
                break;
            case "-":
                System.out.println("Token category: 50, MINUS, value \"" + token + "\"");
                break;
            case "*":
                System.out.println("Token category: 51, MULTIPLY, value \"" + token + "\"");
                break;
            case "/":
                System.out.println("Token category: 52, DIVIDE, value \"" + token + "\"");
                break;
            case "mod":
                System.out.println("Token category: 53, MODULO, value \"" + token + "\"");
                break;
            case "[":
                System.out.println("Token category: 54, LEFT_SQR_BRACE, value \"" + token + "\"");
                break;
            case "]":
                System.out.println("Token category: 55, RIGHT_SQR_BRACE, value \"" + token + "\"");
                break;
            case "(":
                System.out.println("Token category: 56, LEFT_PAREN, value \"" + token + "\"");
                break;
            case ")":
                System.out.println("Token category: 57, RIGHT_PAREN, value \"" + token + "\"");
                break;
            case "\"":
                System.out.println("Token category: 58, DOUBLE_QUOTE, value \"" + token + "\"");
                break;
            case "if":
                System.out.println("Token category: 59, IF keyword, value \"" + token + "\"");
                break;
            case "end":
                System.out.println("Token category: 60, END keyword, value \"" + token + "\"");
                break;
            case "class":
                System.out.println("Token category: 61, CLASS keyword, value \"" + token + "\"");
                break;
            case "true":
                System.out.println("Token category: 62, BOOLEAN, value \"" + token + "\"");
                break;
            case "false":
                System.out.println("Token category: 62, BOOLEAN, value \"" + token + "\"");
                break;
            default:
                // single line comments
                if (token.startsWith("//")){
                    String newStr = token.replace("//", "");
                    System.out.println("Token category: 63, comment, value \"" + newStr + "\"");
                }
                // block comments
                else if (token.startsWith("/*") && token.endsWith("*/")) {
                    String newStr1;
                    newStr1 = token.replace("/*", "");
                    String newStr2 = newStr1.replace("*/", "");
                    System.out.println("Token Category: 63, comment, value \"" + newStr2 + "\"");
                }
                // identifier (contains alphanumeric and _)
                else if (Character.isLetter(token.charAt(0)) && token.matches("\\w+")) {
                    System.out.println("Token category: 64, identifier, value \"" + token + "\"");
                }
                // integers
                else if (token.matches("\\d+")) {
                    System.out.println("Token category: 65, Number, value \"" + token + "\"");
                }
                // decimals
                else if (token.matches("^\\d+\\.\\d+|\\d+\\.\\d+$")) {
                    System.out.println("Token category: 66, Decimal, value \"" + token + "\"");
                }
                // strings
                else if (token.startsWith("\"") && token.endsWith("\"")) {
                    System.out.println("Token category: 67, string, value " + token);
                }
                else{
                    System.out.println("Error: \"" + token + "\" is not allowed");
                }
        }
    }

    /*
     * TypeCheck Function
     * Parameters: a single char
     * Returns a string which helps classify the char
     */
    static String TypeCheck(char C) {
        if (Character.isLetter(C))
            return "L";
        else if (Character.isDigit(C))
            return "D";
        else if (Character.isWhitespace(C))
            return "WS";
        else if (C == '_')
            return "_";
        else if (C == '.')
            return ".";
        else
            return "S";
    }

    /*
     * OpenFile Function
     * Parameters: a file object
     * Prepares a file input stream and called ReadFile() OR returns an error
     */
    static void OpenFile(File inputFile){
        try {
            FileInputStream FileIN = new FileInputStream(inputFile);
            System.out.println("Input: " + inputFile.getName());
            System.out.println("Output:");
            ReadFile(FileIN);
            FileIN.close();
        } catch (Exception e) {
            System.out.println("Error, file not found");
            e.printStackTrace();
        }
    }

    /*
     * ReadFile Function
     * Parameters: FileInputStream object (from OpenFile)
     * reads the file char by char and creates tokens accordingly
     * then calls Tokenizer to analyze each token
     */
    static void ReadFile(FileInputStream FileIN) {
        try {
            int i = 0;
            List<String> Tokens = new ArrayList<>();
            String temp = "";
            String prevType = "";
            String prev = "";
            boolean[] comment = new boolean[2];
            boolean[] blockcomment = new boolean[4];
            boolean strfinder = false;

            //read char by char until EOF
            while ((i = FileIN.read()) != -1) {
                char Cur = (char) i;
                if (Cur == '/') {
                    if (!comment[0] && !blockcomment[0]) {
                        comment[0] = blockcomment[0] = true;        // potential beginning of a comment
                    }
                    else if(comment[0]) {
                        comment[1] = true;
                        blockcomment[0] = false;                    // single line comment has been detected
                    }
                }
                else {
                    if (comment[0]) {
                        comment[0] = false;                         // single line comment has not been detected
                    }
                    if (blockcomment[3]) {
                        blockcomment[3] = false;                    // ending of a block comment hasn't been found
                    }
                }

                // reading and storing strings
                if (Cur == '"') {
                    temp = temp + Cur;
                    int y;
                    while ((y = FileIN.read()) != -1 && !strfinder) {
                        temp = temp + (char)y;
                        if ((char)y == '"') {
                            strfinder = true;
                        }
                    }
                    strfinder = false;
                    Tokens.add(temp);
                    temp = "";
                }

                // block comment has not been detected (but could be single line comment)
                if (blockcomment[0] && Cur != '*' && Cur != '/') {
                    blockcomment[0] = false;
                }

                // end of block comment has not been found
                if (blockcomment[2] && Cur != '/') {
                    blockcomment[2] = false;
                }

                // reading and storing block comments
                if (blockcomment[0] && Cur == '*') {
                    blockcomment[1] = true;
                    temp = temp + Cur;
                    int l;
                    while ((l = FileIN.read()) != -1 && !blockcomment[3]) {
                        if ((char) l == '*') {
                            //could potentially be the end of the comment
                            blockcomment[2] = true;
                        } else if (blockcomment[2] && (char) l == '/') {
                            //end of the comment has been found
                            blockcomment[3] = true;
                        } else {
                            //not at the end of the comment
                            blockcomment[2] = false;
                        }
                        temp = temp + (char) l;
                    }
                    if (!temp.isEmpty()) {
                        Tokens.add(temp);
                    }
                    temp = "";
                    blockcomment[0] = blockcomment[1] = blockcomment[2] = blockcomment[3] = false;
                    comment[0] = comment[1] = false;        // just to be safe
                }

                // reading and storing single line comments
                else if (comment[0] && comment[1]) {
                    blockcomment[0] = blockcomment[1] = blockcomment[2] = blockcomment[3] = false;
                    //read until you reach \n
                    int j;
                    temp = temp + Cur;
                    while ((j = FileIN.read()) != -1 && (char) j != '\n') {
                        temp = temp + (char)j;
                    }
                    if (!temp.isEmpty()) {
                        Tokens.add(temp);
                        comment[0] = comment[1] = false;
                        temp = ""; //   MOVE AFTER IF STMT IF THERES PROBLEMS
                    }
                }
                // current char is not whitespace
                // determine if new token should be created or not
                else if (!Character.isWhitespace(Cur)) {
                    if (prev.matches("\\w+") && Character.toString(Cur).matches("\\w+")) {
                        // making sure identifiers are stored correctly
                    }
                    else if (Cur == '.' && prevType == "D") {   //handling decimals
                        int b;
                        temp = temp + Cur;
                        while ((b = FileIN.read()) != -1 && Character.isDigit((char)b)) {
                            temp = temp + (char)b;
                        }
                        Tokens.add(temp);
                    }
                    //if Cur's type != Prev's type
                    else if (TypeCheck(Cur) != prevType && !temp.isEmpty() || (TypeCheck(Cur) == "S" && prevType == "S")) {
                        if ((!temp.isEmpty() && !temp.matches("\"")) || (temp.matches(".") && prevType != "D" || prevType == "." && TypeCheck(Cur) == ".") ) {
                            Tokens.add(temp);
                        }
                        temp = "";
                    }
                    temp = temp + Cur;
                }
                else {
                    if (!temp.isEmpty() && !temp.matches("\"")) {      //if cur is whitespace, we can create a new token
                        Tokens.add(temp);
                    }
                    temp = "";
                }
                prevType = TypeCheck(Cur);
                prev = Character.toString(Cur);
            }
            if (!Tokens.isEmpty()) {
                if ((Tokens.get(Tokens.size() - 1) != temp) && (!temp.isEmpty()) && !temp.equals("\"")) {
                    Tokens.add(temp);   //ensure last token is added if no blank line at EOF
                }
                int n = 0;
                for (n = 0; n < Tokens.size() - 1; n++) {
                    //handing <=, >=, not=, Not=
                    if ((Tokens.get(n).equals("<") || Tokens.get(n).equals(">") || Tokens.get(n).equals("not") || Tokens.get(n).equals("Not")) && Tokens.get(n+1).equals("=")) {
                            Tokens.set(n,Tokens.get(n) + Tokens.get(n+1));
                            Tokens.remove(n+1);
                    }
                    //making sure decimals don't cause problems
                    if ((Tokens.get(n+1).contains(Tokens.get(n)+'.'))) {
                        Tokens.remove(n+1);
                    }
                    //making sure strings don't cause problems
                    if ((Tokens.get(n).endsWith("\"")) && Tokens.get(n+1).matches("\"")) {
                        Tokens.remove(n+1);
                    }
                }
                for (String s : Tokens) {
                    Tokenizer(s);
                }
            }
        }
        catch (Exception e){
            System.out.println("Error reading file");
        }
    }

    public static void main(String[] args) {

       File homeDir = new File(args[0]);
        String path = homeDir.getAbsolutePath();
        System.out.println("Testing all files in the directory: " + path);
        File[] inputs = homeDir.listFiles();

        for (File file : Objects.requireNonNull(inputs)) {
            if(file.getName().charAt(0) != '.') { //on my operating system, i want to avoid a file called .DS_store
                System.out.println("");
                OpenFile(file);
            }
        }


        /*
        File currFile = new File("/Users/kavyamohan/IdeaProjects/Lexer/out/artifacts/Lexer_jar/SomeFolder/File5.quorum");
        OpenFile(currFile);
        */
    }
}
