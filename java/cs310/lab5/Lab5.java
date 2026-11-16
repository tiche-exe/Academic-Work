import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Lab5 {

    //exercise 1
    static class State {

        String name; //name of the state, e.g. S0

        boolean isInitial; //true if this is the initial state
        boolean isFinal; //true if this is a final state
        
        Map<Character, State> links = new HashMap<>(); //one-directional links: symbol -> next state

        State(String name, boolean isInitial, boolean isFinal) { //constructor
            this.name = name; //set the name
            this.isInitial = isInitial; //set whether it is initial
            this.isFinal = isFinal; //set whether it is final
        }

        void addLink(char symbol, State target) { //adds link from this state to target
            if (symbol != 'a' && symbol != 'b') { //only symbols in {a,b} are allowed
                throw new IllegalArgumentException("Symbol must be 'a' or 'b': " + symbol); //reject anything else
            }
            links.put(symbol, target); //store the link
        }

        State next(char symbol) { //returns the state reached on the given symbol
            return links.get(symbol); //null if there is no link
        }
    }

    static List<State> states = new ArrayList<>(); //all the states in the machine

    static State newState(String name, boolean isInitial, boolean isFinal) {
        State s = new State(name, isInitial, isFinal); 
        states.add(s); //add it to the list
        return s; //return it so links can be added
    }

    static State findInitial() {
        for (State s : states) { //go through every state
            if (s.isInitial) return s; //return the first initial one
        }
        return null; //no initial state defined
    }

    static boolean accepts(String input) { //checks if a string is accepted
        State current = findInitial(); //start at the initial state
        if (current == null) return false; //cannot run without an initial state

        String path = current.name; //keeps track of the states visited
        for (char c : input.toCharArray()) { //read the string one character at a time
            if (c == ' ') continue; //ignore spaces, so "a b b" is read as abb
            current = current.next(c); //follow the link for this symbol
            if (current == null) return false; //no link means the string is rejected
            path += " -" + c + "-> " + current.name; //add the step to the path
        }
        System.out.println("  Path: " + path); //show the path taken
        return current.isFinal; //accepted only if we end in a final state
    }

    static void test(String input) {
        System.out.println("String '" + input + "':");
        boolean ok = accepts(input); //run it through the machine
        System.out.println("  Result: " + (ok ? "ACCEPTED" : "NOT ACCEPTED")); //print result
    }

    //exercise 2:

    public static void main(String[] args) {
        State s0 = newState("S0", true, false);
        State s1 = newState("S1", false, false);
        State s2 = newState("S2", false, false);
        State s3 = newState("S3", false, false);
        State s4 = newState("S4", false, true); //final state

        //we add the link relations
        s0.addLink('a', s1);
        s0.addLink('b', s2);
        s1.addLink('a', s1);
        s1.addLink('b', s3);
        s2.addLink('b', s2);
        s2.addLink('a', s1);
        s3.addLink('a', s1);
        s3.addLink('b', s4);
        s4.addLink('a', s1);
        s4.addLink('b', s2);

        //exercise 3:

        int finalCount = 0;
        int initialCount = 0;

        for (State s : states) { //go through every state
            if (s.isFinal) finalCount++; //count it if final
            if (s.isInitial) initialCount++; //count it if initial
        }
        System.out.println("Number of final states: " + finalCount);
        System.out.println("Number of initial states: " + initialCount);

        //exercise 4: accepted, ends in S4
        test("a b b");
        //exercise 5: not accepted, ends in S1
        test("a a a");
    }
}
