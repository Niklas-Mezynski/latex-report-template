void readSensorData()
{
    rawValue = analogRead(AOUT_PIN); // read the analog value from sensor

    mappedValue = map(rawValue, minADC, maxADC, 0, 100);

    // Add the reading to the rolling average
    total = total - readings[idx] + rawValue;
    readings[idx] = rawValue;

    totalPerc = totalPerc - readingsPerc[idx] + mappedValue;
    readingsPerc[idx] = mappedValue;

    idx = (idx + 1) % NUM_READINGS;

    // Calculate the rolling average
    averageRawMain = total / (float)NUM_READINGS;
    averagePercMain = totalPerc / (float)NUM_READINGS;
}