#include <thread>

using namespace System::Drawing;

void applySepia(Bitmap^ inputImage, Bitmap^ outputImage, int startY, int endY) {
    for (int y = startY; y < endY; y++) {
        for (int x = 0; x < inputImage->Width; x++) {
            Color pixelColor = inputImage->GetPixel(x, y);

            int tr = (int)(0.393 * pixelColor.R + 0.769 * pixelColor.G + 0.189 * pixelColor.B);
            int tg = (int)(0.349 * pixelColor.R + 0.686 * pixelColor.G + 0.168 * pixelColor.B);
            int tb = (int)(0.272 * pixelColor.R + 0.534 * pixelColor.G + 0.131 * pixelColor.B);

            tr = (tr > 255) ? 255 : tr;
            tg = (tg > 255) ? 255 : tg;
            tb = (tb > 255) ? 255 : tb;

            Color sepiaColor = Color::FromArgb(tr, tg, tb);
            outputImage->SetPixel(x, y, sepiaColor);
        }
    }
}

private: System::Void bt_filter_Sepia_MultiThread_Click(System::Object^ sender, System::EventArgs^ e) {
    Bitmap^ inputImage = (Bitmap^)pbox_input->Image;
    if (inputImage == nullptr) return;

    Bitmap^ outputImage = gcnew Bitmap(inputImage->Width, inputImage->Height);
    int midY = inputImage->Height / 2;

    std::thread t1(applySepia, inputImage, outputImage, 0, midY);
    std::thread t2(applySepia, inputImage, outputImage, midY, inputImage->Height);

    t1.join();
    t2.join();

    pbox_output->Image = outputImage;
}
