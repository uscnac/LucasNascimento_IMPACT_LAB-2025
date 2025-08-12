private: System::Void bt_filter_Sepia_MultiThread_Click(System::Object^ sender, System::EventArgs^ e) {
    Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
    Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);

    int startY_Top = 0;
    int endY_Top = inputImage->Height / 2;
    int startY_Botton = inputImage->Height / 2;
    int endY_Botton = inputImage->Height;
    int startX_left = 0;
    int endX_left = inputImage->Width / 2;
    int startX_Right = inputImage->Width / 2;
    int endX_Right = inputImage->Width;

    auto start = high_resolution_clock::now();

    SepiaThreadArgs* threadArgs = new SepiaThreadArgs();
    threadArgs->inputImage = inputImage;
    threadArgs->outputImage = outputImage;
    threadArgs->startX = startX_left;
    threadArgs->endX = endX_left;
    threadArgs->startY = startY_Top;
    threadArgs->endY = endY_Top;

    SepiaThreadArgs* threadArgs_1 = new SepiaThreadArgs();
    threadArgs_1->inputImage = inputImage;
    threadArgs_1->outputImage = outputImage;
    threadArgs_1->startX = startX_Right;
    threadArgs_1->endX = endX_Right;
    threadArgs_1->startY = startY_Botton;
    threadArgs_1->endY = endY_Botton;

    std::thread t1(ApplySepiaFilterWindow_Unmanaged, threadArgs);
    std::thread t2(ApplyBWFilterWindow_Unmanaged, threadArgs_1);

    t1.join();
    t2.join();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    lb_timer->Text = "Calculate Processing duration: " + duration.count().ToString() + " ms";
    textB_Time->Text = "Impact labd 2025";

    delete threadArgs, threadArgs_1;

    pbox_copy->Image = outputImage;
}
