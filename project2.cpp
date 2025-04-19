/**  ∘₊✧────────────────────────────────────────────────✧₊∘ *
 *      project2.cpp
 *     
 *      
 *   ∘₊✧────────────────────────────────────────────────✧₊∘ */

     /* ✧ ✦ ✧───────────────✧ ✦ ✧ *
    *          Include          *
    * ✧ ✦ ✧───────────────✧ ✦ ✧ */
    #include "project2.hpp"
        
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
    using std::reverse;

class Program {

    private:
        /* ✧ ✦ ✧─────────────────────────✧ ✦ ✧ *
         *          Private Variables          *
         * ✧ ✦ ✧─────────────────────────✧ ✦ ✧ */

         vector<string*>* alphabet_;
         string* end_symbol_;

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

         Program () 
         {
            // Defining the alphabet provided in instructions
            this->alphabet_ = new vector<string*> ();
                this->alphabet_->push_back(new string ("i"));
                this->alphabet_->push_back(new string ("+"));
                this->alphabet_->push_back(new string ("-"));
                this->alphabet_->push_back(new string ("*"));
                this->alphabet_->push_back(new string ("/"));
                this->alphabet_->push_back(new string ("("));
                this->alphabet_->push_back(new string (")"));

            this->end_symbol_ = new string ("$");

         }

     /* ✧ ✦ ✧──────────────────✧ ✦ ✧ *
      *          Destructor          *
      * ✧ ✦ ✧──────────────────✧ ✦ ✧ */

         ~Program()
         {
            for (auto pointer : *this->alphabet_)
            {
                delete pointer;
            }

            delete this->end_symbol_;
         }

     /* ✧ ✦ ✧───────────────✧ ✦ ✧ *
      *          Methods          *
      * ✧ ✦ ✧───────────────✧ ✦ ✧ */

      string traceString (const string inputString) {

        auto inputStringIterator = inputString.rbegin();

        while (inputStringIterator != inputString.rend())
        {
            //insert code to do the thing

            inputStringIterator++;
        }

      }

 private:

     /* ✧ ✦ ✧───────────────────────✧ ✦ ✧ *
      *          Private Methods          *
      * ✧ ✦ ✧───────────────────────✧ ✦ ✧ */

}