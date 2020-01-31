#pragma once

extern "C" {
    #include <libavcodec/avcodec.h>
}

class FFMPEGFrame
{
public:
    FFMPEGFrame();
    ~FFMPEGFrame();

    int Init ();
    void Destroy();
    void UnRef();

    int GetSerial();
    int64_t GetPos();
    double GetPts();
    double GetDuration();
    AVFrame* GetFrame();
    int  GetWidth();
    int  GetHeight();
    int  GetFormat();
    AVRational  GetSar();
    bool  IsUploaded();
    bool  IsVerticalFlip();
    AVSubtitle& GetSub();
    
    void UpdateFrame(AVFrame* , double , double , int64_t , int );
    void UpdateSize(FFMPEGFrame *vp);

    
    void SetPos(int64_t );
    void SetDuration(double duration);
    void SetPts(double );
    void SetSerial(int serial);
    void SetWidth(int width);
    void SetHeight(int height);
    void SetUploaded(bool u);
    void SetVerticalFlip(bool v);

    double GetDifference( FFMPEGFrame* nextvp, double max );

private:
    AVFrame *frame;
    AVSubtitle sub;
    int serial;
    double pts;           /* presentation timestamp for the frame */
    double duration;      /* estimated duration of the frame */
    int64_t pos;          /* byte position of the frame in the input file */
    int width;
    int height;
    int format;
    AVRational sar;
    bool uploaded;
    bool flip_v;
};
