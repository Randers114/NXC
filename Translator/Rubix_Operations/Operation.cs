using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rubix_Operations
{
    class Operation
    {
        // Left Doublelayers
        public static void RotateLeftDoubleLayer()
        {

        }

        public static void RotateLeftDoubleLayerInverted()
        {

        }

        // Right doublelayers
        public static void RotateRightDoubleLayer()
        {

        }

        public static void RotateRightDoubleLayerInverted()
        {

        }

        // Down doublelayers
        public static void RotateDownDoubleLayer()
        {

        }

        public static void RotateDownDoubleLayerInverted()
        {

        }

        // Rights
        public static void RotateRightFace(List<List<string>> cube)
        {
            Turn(cube);
            Claw(cube);
            Rotate(cube);
        }

        public static void RotateRightFaceInverted(List<List<string>> cube)
        {
            Turn(cube);
            Claw(cube);
            RotateInverted(cube);
        }

        //Lefts
        public static void RotateLeftFace(List<List<string>> cube)
        {
            TurnInverted(cube);
            Claw(cube);
            Rotate(cube);
        }

        public static void RotateLeftFaceInverted(List<List<string>> cube)
        {
            TurnInverted(cube);
            Claw(cube);
            RotateInverted(cube);
        }

        // Tops
        public static void RotateTopFace(List<List<string>> cube)
        {
            Claw(cube);
            Claw(cube);
            Rotate(cube);
        }

        public static void RotateTopFaceInverted(List<List<string>> cube)
        {
            Claw(cube);
            Claw(cube);
            RotateInverted(cube);
        }

        // Bottoms
        public static void RotateBottomFace(List<List<string>> cube)
        {
            Rotate(cube);
        }

        public static void RotateBottomFaceInverted(List<List<string>> cube)
        {
            RotateInverted(cube);
        }

        // Backs
        public static void RotateBackFace(List<List<string>> cube)
        {
            Claw(cube);
            Rotate(cube);
        }

        public static void RotateBackFaceInverted(List<List<string>> cube)
        {
            Claw(cube);
            RotateInverted(cube);
        }
        
        // Fronts
        public static void RotateFrontFace(List<List<string>> cube)
        {
            ClawInverted(cube);
            Rotate(cube);
        }

        public static void RotateFrontFaceInverted(List<List<string>> cube)
        {
            ClawInverted(cube);
            RotateInverted(cube);
        }


        // Private operations.
        private static void RotateInverted(List<List<string>> cube)
        {
            Rotate(cube);
            Rotate(cube);
            Rotate(cube);
        }

        private static void Claw(List<List<string>> cube)
        {
            List<List<string>> cubeCopy = InitCopy(cube);

            cube[3] = cubeCopy[0];
            cube[0] = cubeCopy[2];
            cube[5] = cubeCopy[3];
            cube[2] = cubeCopy[5];

            ClawLeftAndTurnBottom(cube[1], cubeCopy[1]);
            ClawRightAndTurnTop(cube[4], cubeCopy[4]);
        }

        private static void ClawInverted(List<List<string>> cube)
        {
            Claw(cube);
            Claw(cube);
            Claw(cube);
        }

        private static void Turn(List<List<string>> cube)
        {
            List<List<string>> cubeCopy = InitCopy(cube);

            cube[3] = cubeCopy[1];
            TurnSwapper(cube[1], cubeCopy[2]);
            cube[2] = cubeCopy[4];
            TurnSwapper(cube[4], cubeCopy[3]);

            ClawLeftAndTurnBottom(cube[5], cubeCopy[5]);
            ClawRightAndTurnTop(cube[0], cubeCopy[0]);
        }

        private static void TurnInverted(List<List<string>> cube)
        {
            Turn(cube);
            Turn(cube);
            Turn(cube);
        }

        private static void Rotate(List<List<string>> cube)
        {
            List<List<string>> cubeCopy = InitCopy(cube);

            ClawLeftAndTurnBottom(cube[5], cubeCopy[5]);

            LeftToFront(cube[2], cubeCopy[4]);
            FrontToRight(cube[1], cubeCopy[2]);
            RightToBack(cube[3], cubeCopy[1]);
            BackToLeft(cube[4], cubeCopy[3]);

        }

        private static void ClawLeftAndTurnBottom(List<string> cubeSide, List<string> cubeSideCopy)
        {
            cubeSide[2] = cubeSideCopy[0];
            cubeSide[5] = cubeSideCopy[1];
            cubeSide[8] = cubeSideCopy[2];
            cubeSide[1] = cubeSideCopy[3];
            cubeSide[7] = cubeSideCopy[5];
            cubeSide[0] = cubeSideCopy[6];
            cubeSide[3] = cubeSideCopy[7];
            cubeSide[6] = cubeSideCopy[8];
        }

        private static void ClawRightAndTurnTop(List<string> cubeSide, List<string> cubeSideCopy)
        {
            cubeSide[6] = cubeSideCopy[0];
            cubeSide[3] = cubeSideCopy[1];
            cubeSide[0] = cubeSideCopy[2];
            cubeSide[7] = cubeSideCopy[3];
            cubeSide[1] = cubeSideCopy[5];
            cubeSide[8] = cubeSideCopy[6];
            cubeSide[5] = cubeSideCopy[7];
            cubeSide[2] = cubeSideCopy[8];
        }

        private static void TurnSwapper(List<string> cubeSide, List<string> cubeSideCopy)
        {
            int i = 8;
            foreach (string item in cubeSideCopy)
            {
                cubeSide[i] = item;
                i--;
            }
        }

        private static void LeftToFront(List<string> cubeSide, List<string> cubeSideCopy)
        {
            cubeSide[6] = cubeSideCopy[2];
            cubeSide[7] = cubeSideCopy[1];
            cubeSide[8] = cubeSideCopy[0];
        }

        private static void FrontToRight(List<string> cubeSide, List<string> cubeSideCopy)
        {
            cubeSide[6] = cubeSideCopy[6];
            cubeSide[7] = cubeSideCopy[7];
            cubeSide[8] = cubeSideCopy[8];
        }

        private static void RightToBack(List<string> cubeSide, List<string> cubeSideCopy)
        {
            cubeSide[2] = cubeSideCopy[6];
            cubeSide[1] = cubeSideCopy[7];
            cubeSide[0] = cubeSideCopy[8];
        }

        private static void BackToLeft(List<string> cubeSide, List<string> cubeSideCopy)
        {
            cubeSide[0] = cubeSideCopy[0];
            cubeSide[1] = cubeSideCopy[1];
            cubeSide[2] = cubeSideCopy[2];
        }



        private static List<List<string>> InitCopy(List<List<string>> cube)
        {
            List<List<string>> cubeCopy = new List<List<string>>(cube);
            int i = 0, a = 0;

            foreach (var item in cube)
            {
                cubeCopy[a] = new List<string>(cube[a]);
                a++;
            }

            return cubeCopy;
        }
    }
}