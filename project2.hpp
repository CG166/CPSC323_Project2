#ifndef PROJECT2_HPP
#define PROJECT2_HPP

    /* ✧ ✦ ✧───────────────✧ ✦ ✧ *
    *          Include          *
    * ✧ ✦ ✧───────────────✧ ✦ ✧ */
        
    #include <iostream>
    #include <fstream>
    #include <string>

/* ✧ ✦ ✧─────────────✧ ✦ ✧ *
*          Using          *
* ✧ ✦ ✧─────────────✧ ✦ ✧ */
    using std::cout;
    using std::endl;
    using std::vector;
    using std::string;

class Program {

    private:
        /* ✧ ✦ ✧─────────────────────────✧ ✦ ✧ *
         *          Private Variables          *
         * ✧ ✦ ✧─────────────────────────✧ ✦ ✧ */

         vector<char*>* alphabet_;
         char* end_symbol_;

         // Variables for debugging :)
         bool debug = false;

         string tab = "    ";
         string divider = "----------------------------------------------------------------------------------------------------";

         string centerText(string text)
            {
                int spaces = 50 - (text.size() / 2);
                string result;
                result.append(spaces, ' ');
                result = result + text;
                return result;
            }

    public:

        /* ✧ ✦ ✧────────────────────✧ ✦ ✧ *
         *          Constructors          *
         * ✧ ✦ ✧────────────────────✧ ✦ ✧ */

         Program ();

     /* ✧ ✦ ✧──────────────────✧ ✦ ✧ *
      *          Destructor          *
      * ✧ ✦ ✧──────────────────✧ ✦ ✧ */

         ~Program();

     /* ✧ ✦ ✧───────────────✧ ✦ ✧ *
      *          Methods          *
      * ✧ ✦ ✧───────────────✧ ✦ ✧ */


 private:

     /* ✧ ✦ ✧───────────────────────✧ ✦ ✧ *
      *          Private Methods          *
      * ✧ ✦ ✧───────────────────────✧ ✦ ✧ */

}

#endif