package Logging;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.LogRecord;
import java.util.logging.SimpleFormatter;

public class CustomFormatter extends SimpleFormatter {
    private static String DATE_FORMAT  = "dd/MM/yyyy HH:mm:ss";
    private static SimpleDateFormat sdf = new SimpleDateFormat(DATE_FORMAT);

    @Override
        public String format(LogRecord record) {
            StringBuilder sb = new StringBuilder();
            sb.append(sdf.format(new Date(record.getMillis())))
              .append(" ")
              .append("[").append(record.getLevel()).append("] ")
              .append(formatMessage(record))
              .append(System.lineSeparator());
            return sb.toString();
        }
}
