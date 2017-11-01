void InitializeCube()/* init with hardcoded colors */
{
	InitializeSide('w','b','y','y','b','r','b','g','o', 0); /* init top */
	InitializeSide('y','b','b','b','r','r','b','g','g', 1);	/* init right */
	InitializeSide('w','w','b','r','w','y','w','w','w', 2);	/* init front */
	InitializeSide('y','g','r','b','y','y','g','w','r', 3);	/* init back */
	InitializeSide('r','o','o','o','o','g','o','o','o', 4);	/* init left */
	InitializeSide('g','r','r','w','g','o','g','y','y', 5);	/* init buttom */
}

void InitializeCubeTest()
{
	InitializeSide('o','o','y','r','g','r','y','b','g', 0); /* init top */
	InitializeSide('r','w','b','y','o','w','o','b','o', 1);	/* init right */
	InitializeSide('g','y','w','g','w','o','w','w','w', 2);	/* init front */
	InitializeSide('b','g','b','g','y','g','y','b','b', 3);	/* init back */
	InitializeSide('g','y','r','w','r','r','w','o','g', 4);	/* init left */
	InitializeSide('r','r','r','y','b','b','o','o','y', 5);	/* init buttom */
}

void FillTestCube()
{
	for(int j = 0; j < 6; j++)
	{
    for(int i = 0; i < 9; i++)
    {
      testCube[j][i] = myCube[j][i];
    }
		//memcpy(Testcube1.sides[j], myCube[j], 9);
	}
}

void Resetcube()
{
	for(int j = 0; j < 6; j++)
	{
    for(int i = 0; i < 9; i++)
    {
      myCube[j][i] = testCube[j][i];
    }
		//memcpy(myCube[i], Testcube1.sides[i], 9);
	}
}



void TestMethods()
{
	RotateButtomRight();
	if(	strncmp(myCube[5],"oyrobrybr",9) == 0 /* COORECT */
		&& strncmp(myCube[1], "wwwyowobo",9) == 0 /* CORRECT */
		&& strncmp(myCube[2], "gywgwowog",9) == 0 /*CORRECT */
		&& strncmp(myCube[3], "rwbgygybb",9) == 0) /* CORRECT*/
		{
			//printf("Test 1 succes!\n");
		}

	else
	{
			for (int i = 0; i < 9; i++)
			//printf("%c", myCube[5][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[1][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[2][i]);
		//printf("\n");
		for (int i = 0; i < 9; i++)
			//printf("%c", myCube[3][i]);
		//printf("\n");
	}

	Resetcube();

	ClawPull();
	if(	strncmp(myCube[0],"gywgwowww",9) == 0 /* CORRECT */
		&& strncmp(myCube[1], "oyrbowowb",9) == 0 /* CORRECT */
		&& strncmp(myCube[2], "rrrybbooy",9) == 0 /* CORRECT */
		&& strncmp(myCube[3], "ooyrgrybg",9) == 0 /* CORRECT */
		&& strncmp(myCube[4], "rrgyrogww",9) == 0 /* CORRECT */
		&& strncmp(myCube[5], "bgbgygybb",9) == 0) /* CORRECT */
		{
			//printf("Test 2 succes!\n");
		}
	else
	{
			for (int i = 0; i < 9; i++)
			//printf("%c", myCube[0][i]);
		//printf("\n");

				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[1][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[2][i]);
		//printf("\n");
		for (int i = 0; i < 9; i++)
			//printf("%c", myCube[3][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[4][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[5][i]);
		//printf("\n");
	}

	Resetcube();

	TurnCubeRight();
	if(	strncmp(myCube[0],"yrgogbory",9) == 0 /* COORECT */
		&& strncmp(myCube[1], "wwwowgwyg",9) == 0 /* COORECT */
		&& strncmp(myCube[2], "gyrwrrwog",9) == 0 /* CORRECT */
		&& strncmp(myCube[3], "rwbyowobo",9) == 0 /* CORRECT */
		&& strncmp(myCube[4], "bbygygbgb",9) == 0 /* CORRECT */
		&& strncmp(myCube[5], "oyrobrybr",9) == 0) /* COORECT */
		{
			//printf("Test 3 succes!\n");
		}
	else
	{

			for (int i = 0; i < 9; i++)
			//printf("%c", myCube[0][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[1][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[2][i]);
		//printf("\n");
		for (int i = 0; i < 9; i++)
			//printf("%c", myCube[3][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[4][i]);
		//printf("\n");
				for (int i = 0; i < 9; i++)
			//printf("%c", myCube[5][i]);
		//printf("\n");

	}

	Resetcube();
}
