#include "eightpuzzle.h"

/* implementation of successor function */
std::vector<std::pair<Moves, std::string>> EightPuzzle::sucessor_fun (const std::string& s) const
{
	std::vector<std::pair<Moves, std::string>> suc;
	char temp;

	switch (s.find ('0'))
	{
		case 0:
        {
        	std::string s0 (s);
			std::string s1 (s);
                
            temp = s0[3];
        	s0[3] = s0[0];
        	s0[0] = temp;

        	temp = s1[1];
        	s1[1] = s1[0];
        	s1[0] = temp;

        	suc.push_back (std::make_pair (Moves::down, s0));
            suc.push_back (std::make_pair (Moves::right, s1));
        }

		return suc;

		case 1:
		{
			std::string s0 (s);
			std::string s1 (s);
            std::string s2 (s);

			temp = s0[4];
        	s0[4] = s0[1];
        	s0[1] = temp;

        	temp = s1[0];
        	s1[0] = s1[1];
        	s1[1] = temp;

        	temp = s2[2];
		    s2[2] = s2[1];
			s2[1] = temp;

        	suc.push_back (std::make_pair (Moves::down, s0));
            suc.push_back (std::make_pair (Moves::left, s1));
            suc.push_back (std::make_pair (Moves::right, s2));
		}

		return suc;

		case 2:
		{
			std::string s0 (s);
			std::string s1 (s);

			temp = s0[5];
        	s0[5] = s0[2];
        	s0[2] = temp;

        	temp = s1[1];
        	s1[1] = s1[2];
        	s1[2] = temp;

            suc.push_back (std::make_pair (Moves::down, s0));
            suc.push_back (std::make_pair (Moves::left, s1));
		}

		return suc;

		case 3:
		{
			std::string s0 (s);
			std::string s1 (s);
			std::string s2 (s);

			temp = s0[6];
        	s0[6] = s0[3];
        	s0[3] = temp;

        	temp = s1[4];
        	s1[4] = s1[3];
        	s1[3] = temp;

        	temp = s2[0];
			s2[0] = s2[3];
			s2[3] = temp;

        	suc.push_back (std::make_pair (Moves::down, s0));
            suc.push_back (std::make_pair (Moves::right, s1));
            suc.push_back (std::make_pair (Moves::up, s2));
		}

		return suc;

		case 4:
		{
			std::string s0 (s);
			std::string s1 (s);
			std::string s2 (s);
			std::string s3 (s);

			temp = s0[1];
		    s0[1] = s0[4];
		    s0[4] = temp;

			temp = s1[7];
			s1[7] = s1[4];
			s1[4] = temp;

			temp = s2[5];
			s2[5] = s2[4];
			s2[4] = temp;

			temp = s3[3];
			s3[3] = s3[4];
			s3[4] = temp;

        	suc.push_back (std::make_pair (Moves::up, s0));
            suc.push_back (std::make_pair (Moves::down, s1));
            suc.push_back (std::make_pair (Moves::right, s2));
            suc.push_back (std::make_pair (Moves::left, s3));
		}

		return suc;

		case 5:
		{
			std::string s0 (s);
			std::string s1 (s);
            std::string s2 (s);

			temp = s0[8];
        	s0[8] = s0[5];
        	s0[5] = temp;

        	temp = s1[4];
        	s1[4] = s1[5];
        	s1[5] = temp;

        	temp = s2[2];
		    s2[2] = s2[5];
			s2[5] = temp;

        	suc.push_back (std::make_pair (Moves::down, s0));
            suc.push_back (std::make_pair (Moves::left, s1));
            suc.push_back (std::make_pair (Moves::up, s2));
		}

		return suc;

		case 6:
		{
			std::string s0 (s);
			std::string s1 (s);

			temp = s0[3];
        	s0[3] = s0[6];
        	s0[6] = temp;

        	temp = s1[7];
        	s1[7] = s1[6];
        	s1[6] = temp;

            suc.push_back (std::make_pair (Moves::up, s0));
            suc.push_back (std::make_pair (Moves::right, s1));
		}

		return suc;

		case 7:
		{
			std::string s0 (s);
			std::string s1 (s);
            std::string s2 (s);

			temp = s0[4];
        	s0[4] = s0[7];
        	s0[7] = temp;

        	temp = s1[6];
        	s1[6] = s1[7];
        	s1[7] = temp;

        	temp = s2[8];
			s2[8] = s2[7];
			s2[7] = temp;

        	suc.push_back (std::make_pair (Moves::up, s0));
            suc.push_back (std::make_pair (Moves::left, s1));
            suc.push_back (std::make_pair (Moves::right, s2));
		}

		return suc;

		case 8:
		{
			std::string s0 (s);
			std::string s1 (s);

			temp = s0[5];
        	s0[5] = s0[8];
        	s0[8] = temp;

        	temp = s1[7];
        	s1[7] = s1[8];
        	s1[8] = temp;

        	suc.push_back (std::make_pair (Moves::up, s0));
            suc.push_back (std::make_pair (Moves::left, s1));
		}

		return suc;
	}
}