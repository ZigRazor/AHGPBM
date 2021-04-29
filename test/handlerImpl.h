#ifndef DB1841C9_5381_450C_8803_0A781AB3102E
#define DB1841C9_5381_450C_8803_0A781AB3102E


class handler1 : public AHGPBM::Handler
{
public:
    handler1() : result(0) {}

    void *run(google::protobuf::Message *msg)
    {
        //std::cout << "Handled " << msg->GetDescriptor()->name() << std::endl;
        result = 1;
        int *result_to_return = new int(result);
        return result_to_return;
    }

    int getResult()
    {
        return result;
    }

private:
    int result;
};

class handler2 : public AHGPBM::Handler
{
public:
    handler2() : result(0) {}

    void *run(google::protobuf::Message *msg)
    {
        //std::cout << "Handled " << msg->GetDescriptor()->name() << std::endl;
        result = 2;
        int *result_to_return = new int(result);
        return result_to_return;
    }

    int getResult()
    {
        return result;
    }

private:
    int result;
};

#endif /* DB1841C9_5381_450C_8803_0A781AB3102E */
