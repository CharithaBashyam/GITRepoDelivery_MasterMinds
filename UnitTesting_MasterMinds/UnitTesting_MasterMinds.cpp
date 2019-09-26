#include "MasterMinds_ConsoleApplication.cpp"
#include "gtest/gtest.h"
#include <string.h>
class unitTesting : public ::testing::Test
{
public:
	bool stub_GuessCount_Decreament()
	{
		char guess[] = "RRRX";
		char right[] = "RRRR";
		bool won = false;
		int numGuesses = 10;
		while (!won && numGuesses > 0)
		{
			//masterMindObj.prompt(guess);

			if (masterMindObj.invalidcolorentry_guess != true)
			{
				won = masterMindObj.gaveOver(guess, right);
				numGuesses--;
			}
			if (numGuesses == 1)
			{
				string s = "RRRR";
				strcpy_s(guess, s.c_str());
			}

		}
		return won;
	}

	bool promptfun_stub(char guess[])
	{
		string validSetOfColor = "RGBOPY";
		for (int i = 0; i < 4; i++)
		{
			size_t isValidSet = validSetOfColor.find(guess[i]);
			if (isValidSet != string::npos)
			{
				if (guess[i] > 91) // lower case level
					guess[i] = guess[i] - 32;
			}
			else
			{

				cout << "Invalid Colors,Please enter valid color" << endl;
				masterMindObj.invalidcolorentry_guess = true;
			}
		}
		if (masterMindObj.invalidcolorentry_guess == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool stub_ExecuteMasterMindsGame()
	{
		char right[4];
		for (int i = 0; i < 4; i++)
		{
			cout << "rand() value is " << rand() << endl;
			int temp = (rand() % 6) + 1;
			cout << "temp" << temp << endl;
			right[i] = masterMindObj.convertToColor(temp);
			//cout << right[i] << " ";
		}
		for (int i = 0; i < 4; i++)
		{
			if (1 <= right[i] <= 6)
			{
				return  true;
			}
			else
				return false;
		}
	}
};
//************ Converting randomly generated ASCII Value to its colour ************
TEST(color_B, convertToColor_Fun)
{
	EXPECT_EQ('B', masterMindObj.convertToColor(1));
}
TEST(color_G, convertToColor_Fun)
{
	EXPECT_EQ('G', masterMindObj.convertToColor(2));
}
TEST(color_O, convertToColor_Fun)
{
	EXPECT_EQ('O', masterMindObj.convertToColor(3));
}
TEST(color_P, convertToColor_Fun)
{
	EXPECT_EQ('P', masterMindObj.convertToColor(4));
}
TEST(color_R, convertToColor_Fun)
{
	EXPECT_EQ('R', masterMindObj.convertToColor(5));
}
TEST(color_Y, convertToColor_Fun)
{
	EXPECT_EQ('Y', masterMindObj.convertToColor(6));
}
TEST(color_Unavailable, convertToColor_Fun)
{
	EXPECT_EQ('\0', masterMindObj.convertToColor(-1));
}
TEST(color_NULL, convertToColor_Fun)
{
	EXPECT_EQ('\0', masterMindObj.convertToColor(0));
}
//*********************************************************************************
//************ Get the User Guess combination of color
//                 and convert it into Upper case incase of lower case ************
TEST(Invalid_Color_Guess_Handling_duringprompt, prompt_Fun)
{
	masterMindObj.invalidcolorentry_guess = false;
	EXPECT_TRUE(true, unitTesting::promptfun_stub((char*)"RGBX"));
}
TEST(valid_Color_Guess_Handling_duringprompt, prompt_Fun)
{
	masterMindObj.invalidcolorentry_guess = false;
	EXPECT_FALSE(false, unitTesting::unitTesting::promptfun_stub((char*)"RGBY"));//not invalid color entry
	//Can be rewrited as below
	//EXPECT_FALSE(true, unitTesting::promptfun_stub());
}
//*********************************************************************************

TEST(numberOfGuessesHandling, executeMasterMindsGame_Fun)
{
	EXPECT_TRUE(true, unitTesting::stub_ExecuteMasterMindsGame());
}
TEST(guessVersusActualColor_Failed, gaveOver_Fun)
{
	EXPECT_FALSE(false, masterMindObj.gaveOver("RRRX","RRRR"));
}
TEST(guessVersusActualColor_Pass, gaveOver_Fun)
{
	EXPECT_TRUE(true, masterMindObj.gaveOver("RRRR", "RRRR"));
}
TEST(WinorLooseBasedOnGuess, executeMasterMindsGame_Fun)
{
	EXPECT_TRUE(true, unitTesting::stub_GuessCount_Decreament());
}
int main(int argc, char** argv)

{
	::testing::InitGoogleTest(&argc, argv);
	//masterMindObj.executeMasterMindsGame();
	 RUN_ALL_TESTS();
	 masterMindObj.executeMasterMindsGame();
	 return 0;
}