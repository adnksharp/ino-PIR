#define pir 2
#define led LED_BUILTIN
unsigned long Go, Delay = 5000;
bool state = true, cache;

bool PIR()
{
    bool out = cache;
    if (digitalRead(pir))
    {
        if (state)
            out = true;
        state = false;
    }
    else
    {
        if (!state)
            Go = millis();
        if (millis() - Go == Delay)
            out = false;
        state = true;
    }
    cache = out;
    return out;
}

void setup()
{
    pinMode(pir, INPUT);
    pinMode(led, OUTPUT);
}

void loop()
{
    digitalWrite(led, PIR());
}