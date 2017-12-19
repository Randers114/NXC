using System;
using System.Diagnostics;
using System.Threading;
using MonoBrick.NXT;
using System.Reflection;

namespace BluetoothCommunicator
{
    class Program
    {
        static void Main(string[] args)
        {
            string initialFileName = "initialCube.txt", uploadFileName = "cube_path.txt", mainProgramName = "PCWithNXC.rxe";
            bool fileFromNXTExists = false;
            var brick = new Brick<Sensor, Sensor, Sensor, Sensor>("com4");
            BrickFile downloadFile = null;

            brick.Connection.Open();

            brick.StartProgram(mainProgramName);

            BrickFile[] initiaryList = brick.FileSystem.FileList();

            foreach (var item in initiaryList)
            {
                if (item.Name == initialFileName)
                {
                    brick.FileSystem.DeleteFile(item);
                }
                else if (item.Name == uploadFileName)
                {
                    brick.FileSystem.DeleteFile(item);
                }
            }


            while (!fileFromNXTExists)
            {
                BrickFile[] list = brick.FileSystem.FileList();

                foreach (var item in list)
                {
                    if (item.Name == initialFileName)
                    {
                        fileFromNXTExists = true;
                        Thread.Sleep(3000);
                        downloadFile = item;
                    }
                    else if (item.Name == uploadFileName)
                    {
                        brick.FileSystem.DeleteFile(item);
                    }
                }

                Thread.Sleep(500);
            }

            brick.FileSystem.DownloadFile(initialFileName, downloadFile);

            Process process = Process.Start(System.IO.Path.GetDirectoryName(Assembly.GetExecutingAssembl‌​y().Location) + "/" + "SearchGraph.exe", System.IO.Path.GetDirectoryName(Assembly.GetExecutingAssembl‌​y().Location));

            process.WaitForExit();

            brick.FileSystem.UploadFile(System.IO.Path.GetDirectoryName(Assembly.GetExecutingAssembl‌​y().Location) + "/" + uploadFileName, uploadFileName);
        }
    }
}
